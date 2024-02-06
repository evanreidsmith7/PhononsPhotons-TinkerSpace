#!usr/bin/python
#----------------------------------------------------------------------------- #
#----------------------------------------------------------------------------- #
#  >>> generate_stm32  
#
#  Purpose: Generate all the necessary files for loading/validating an ML model 
#           onto STM32
#  
#  Functions: n/a
#
#  Dependencies: n/a
#  
#  Description: Pre-processes data, compile, train, and save model as .tflite. 
#               Save input/output data as .npy for model validation in STM32IDE
#
#  Usage:
#  python generate_stm32.py {Dir name of dataset w R0-RN reg} {desired model name}
# 
#  Notes: - Set N_REGIONS to the number of regions in dataset directory
#         - Dont push datasets to repo (too large), add them locally before running.
#         - Replace build_model() with script that compiles/trains if adding new model.
#
#----------------------------------------------------------------------------- #
#----------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
#                                IMPORTS
# ---------------------------------------------------------------------------- #
import sys
import os 
import copy
import shutil
import pandas as pd
import numpy  as np
import tensorflow as tf
from datetime import datetime

from sklearn.preprocessing   import StandardScaler
from sklearn.preprocessing   import LabelEncoder
from tensorflow.keras.models import Sequential
from sklearn.model_selection import train_test_split
from tensorflow.keras.layers import Dense, Dropout
# ---------------------------------------------------------------------------- #
#                                GLOBALS
# ---------------------------------------------------------------------------- #

# ----------------------------------- #
#  Paths
# ----------------------------------- #
MODEL_PATH = os.path.join(os.getcwd(), "ANNmodels")
DSET_PATH  = os.path.join(os.getcwd(), "Datasets" )
OUT_PATH   = os.path.join(os.getcwd(), "Output"   )

DT_FORMAT  = "%m_%d_%H%M%S"
DATETIME   = datetime.now().strftime(DT_FORMAT)
N_REGIONS  = 5 


# ---------------------------------------------------------------------------- #
#                               FUNCTIONS 
# ---------------------------------------------------------------------------- #

# ---------------------------------------------------------------------------- #
# Function  : load_csv_files 
# Arguments : directory
# Returns   : dataset
#
# Description:  Load CSV files found in directory
#               
#              
# ---------------------------------------------------------------------------- # 
def load_csv_files(directory):

    dataset = pd.DataFrame()
    for filename in os.listdir(directory):
        if filename.endswith(".csv"):
            file_path = os.path.join(directory, filename)
            df = pd.read_csv(file_path)
            dataset = pd.concat([dataset, df], ignore_index=True)
    return dataset

# =/ load_csv_files /= #

# ---------------------------------------------------------------------------- #
# Function  : data_preprocessing 
# Arguments : region_path
# Returns   : n/a
#
# Description:  Concat datasets, encode, etc.
#               
#              
# ---------------------------------------------------------------------------- # 
def data_preprocessing(region_path,model_name):

    # Dataframe to store entire dataset
    full_dataset = pd.DataFrame()

    # Load CSV files from each region and concatenate them
    for region in range(1,N_REGIONS + 1):

        region_dataset = load_csv_files(os.path.join(region_path, f"R{region}"))
        full_dataset   = pd.concat([full_dataset, region_dataset], ignore_index=True)

    # Handling missing values by dropping rows with missing values
    full_dataset.dropna(inplace=True)

    # Display the shape of the combined dataset
    print("Shape of the combined dataset:", full_dataset.shape)

    y = full_dataset["Region"]
    # encode y
    le = LabelEncoder()
    y_encoded = le.fit_transform(y)


    X = full_dataset.drop(["Region"], axis=1)
    # Convert empty strings to NaN
    X[X == ''] = np.nan

    # Convert all values to float
    X = X.astype(float)

    print("X: ", X.shape)
    print("y: ", y_encoded.shape)

    # Create numpy arrays for data validation
    x_temp = copy.deepcopy(X)
    x_temp.insert(0,"Region",y_encoded)

    validation_inputs  = x_temp.to_numpy()
    validation_outputs = y_encoded

    valid_path    = os.path.join(OUT_PATH,"Validation")
    model_name_dt = f"{DATETIME}_{model_name}"

    if os.path.isdir(os.path.join(valid_path,model_name)):

       shutil.rmtree(os.path.join(valid_path,model_name))
       os.mkdir(os.path.join(valid_path,model_name))
    else:
       os.mkdir(os.path.join(valid_path,model_name)) 

    np.save(f"{valid_path}/{model_name}/{model_name_dt}_validation_inputs.npy" ,validation_inputs)
    #TODO: Fix validation outputs, not working on CubeMX 
    np.save(f"{valid_path}/{model_name}/{model_name_dt}_validation_outputs.npy",validation_outputs)

    print("\n******************************************************************")
    print("******************************************************************")
    print(f"Validation files Saved to {os.path.join(valid_path,model_name)}")
    print("******************************************************************")
    print("******************************************************************\n")

    return X, y_encoded 

# =/ data_preprocessing /= #

# ---------------------------------------------------------------------------- #
# Function  : build_model 
# Arguments : X,y
# Returns   : n/a
#
# Description:  Compiles and trains model. Outputs .keras, savedModel, 
#               .tflite models to /Output/Models
#               
#              
# ---------------------------------------------------------------------------- # 
def build_model(X,y_encoded,model_name):
    
    # ----------------------------------- #
    #  Train/Test Split
    # ----------------------------------- #
     
    X_train, X_test, y_train, y_test = train_test_split(X, y_encoded, test_size=0.2, random_state=42)

    # Standardize features
    scaler = StandardScaler()

    X_train_scaled = scaler.fit_transform(X_train)
    X_test_scaled = scaler.transform(X_test)

    # ----------------------------------- #
    #  Create the Model
    # ----------------------------------- #
    
    print("Creating the model...")

    model = Sequential()

    #Input layer 762 neurons (number of features)
    model.add(Dense(units=762, input_dim=762, activation='relu'))
    #Hidden layers (you can adjust the number of layers and neurons)
    model.add(Dense(units=256, activation='relu'))
    model.add(Dropout(0.2))
    model.add(Dense(units=128, activation='relu'))
    #dropout layer
    #Output layer
    model.add(Dense(units=5, activation='softmax'))

    #Compile the model
    print("Compiling the model...")

    model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['acc'])
    
    # ----------------------------------- #
    #  Train the model
    # ----------------------------------- #
    
    print("Training the model...")

    history = model.fit(X_train_scaled, y_train, epochs=100, batch_size=64, validation_data =(X_test_scaled, y_test), verbose=1)
    
    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    model_path      = os.path.join(OUT_PATH,"Models")
    model_name_dt = f"{DATETIME}_{model_name}"

    if os.path.isdir(os.path.join(model_path,model_name)):

       shutil.rmtree(os.path.join(model_path,model_name))
       os.mkdir(os.path.join(model_path,model_name))
    else:
       os.mkdir(os.path.join(model_path,model_name)) 

    model.save(f"{model_path}/{model_name}/{model_name_dt}.keras")
    tf.saved_model.save(model,os.path.join(model_path,model_name))

            
    converter = tf.lite.TFLiteConverter.from_saved_model(os.path.join(model_path,model_name))
    tflite_model = converter.convert()

    with open(f"{os.path.join(model_path,model_name)}/{model_name_dt}.tflite",'wb') as f:
        f.write(tflite_model)

    # Cant choose name for saved model?? rename it
    old_file = os.path.join(model_path,model_name, "saved_model.pb")
    new_file = os.path.join(model_path,model_name, f"{model_name_dt}_saved_model.pb")

    os.rename(old_file,new_file)

    print("\n******************************************************************")
    print("******************************************************************")
    print(f"Model files Saved to {os.path.join(model_path,model_name)}")
    print("******************************************************************")
    print("******************************************************************\n")

# =/ build_model /= #

# ---------------------------------------------------------------------------- #
# Function  : main 
# Arguments : dataset_dir,model_name
# Returns   : 
#
# Description:  
#               
#              
# ---------------------------------------------------------------------------- # 
def main(dataset_dir,model_name):

    reg_path = os.path.join(DSET_PATH, dataset_dir)
    X,y      = data_preprocessing(reg_path,model_name)
    build_model(X,y,model_name)

    return 

# =/ main /= #


if __name__ == "__main__":
    if len(sys.argv) != 3:
        print("ERROR: 2 arguments required")
        sys.exit(0)
    else:  
        main(sys.argv[1],sys.argv[2])
    














