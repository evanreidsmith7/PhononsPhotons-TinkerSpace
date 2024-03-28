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
import keras
import shutil
import pandas as pd
import numpy  as np
import tensorflow as tf
import seaborn as sns
import matplotlib.pyplot as plt

from umap     import UMAP
from datetime import datetime
from keras    import layers
from keras    import models
from keras    import backend as K

import tensorflow_model_optimization as tfmot
from sklearn.preprocessing         import StandardScaler
from sklearn.preprocessing         import LabelEncoder
from sklearn.manifold              import TSNE
from tensorflow.keras.models       import Sequential
from sklearn.model_selection       import train_test_split
from tensorflow.keras.layers       import Dense, Dropout
from tensorflow.keras.regularizers import l2
from sklearn.metrics               import classification_report, confusion_matrix,\
                                          accuracy_score, precision_score, auc,   \
                                          recall_score, f1_score, roc_curve
from sklearn.discriminant_analysis import LinearDiscriminantAnalysis as LDA
# ---------------------------------------------------------------------------- #
#                                GLOBALS
# ---------------------------------------------------------------------------- #

# ----------------------------------- #
#  Paths
# ----------------------------------- #
MODEL_PATH = os.path.join(os.getcwd(), "ANNmodels")
DSET_PATH  = os.path.join(os.getcwd(), "Datasets" )
OUT_PATH   = os.path.join(os.getcwd(), "Output"   )
EVAL_PATH  = os.path.join(os.getcwd(), "Evaluate" )

DT_FORMAT  = "%m_%d_%H%M%S"
DATETIME   = datetime.now().strftime(DT_FORMAT)
N_REGIONS  = 12 


# ---------------------------------------------------------------------------- #
#                               FUNCTIONS 
# ---------------------------------------------------------------------------- #


# ---------------------------------------------------------------------------- #
# Function  : plot_confusion_matrix 
# Arguments : y_labels,y_preds,save_location,title
# Returns   : 
#
# Description:  Plots confusion matrix
#               
#              
# ---------------------------------------------------------------------------- # 
def plot_confusion_matrix(y_labels,y_preds,title,model_name):

    print("Plotting " + title + " confusion matrix...")

    confusion_data = confusion_matrix(y_labels, y_preds)
    
    # ----------------------------------- #
    #  Configure and plot data
    # ----------------------------------- #
    
    plt.figure(figsize=(8, 6))
    sns.heatmap(confusion_data, annot=True, fmt="d", cmap="Blues", annot_kws={"size": 16})

    plt.xlabel("Predicted")
    plt.ylabel("True")
    plt.title(title)

    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    eval_path    = os.path.join(EVAL_PATH,"Models")
    eval_path_dt = f"{DATETIME}_{model_name}"

    if os.path.isdir(os.path.join(eval_path,model_name)):

       shutil.rmtree(os.path.join(eval_path,model_name))
       os.makedirs(os.path.join(eval_path,model_name))

    else:
       os.makedirs(os.path.join(eval_path,model_name)) 

    plt.savefig(os.path.join(eval_path,model_name,f"{model_name}_Confusion_Matrix.png"))
    plt.close()


    print("done...")

    return 
# =/ plot_confusion_matrix /=



# ---------------------------------------------------------------------------- #
# Function  : plot_roc_auc 
# Arguments : y_test,y_prob,save_location
# Returns   : N/a
#
# Description:  Plots the ROC AUC of the tested model
#               
#              
# ---------------------------------------------------------------------------- # 
def plot_roc_auc(y_test,y_prob,model_name):

    n_classes = len(np.unique(y_test))

    fpr = dict()
    tpr = dict()
    roc_auc = dict()

    # Calculate ROC curver
    for i in range(n_classes):
       fpr[i], tpr[i], _ = roc_curve(np.array(pd.get_dummies(y_test))[:, i], y_prob[:, i])
       roc_auc[i] = auc(fpr[i], tpr[i])

    # Plot Class ROC AUC
    plt.figure(figsize=(8, 6))
    for i in range(n_classes):
       plt.plot(fpr[i], tpr[i], lw=2,
                label='ROC curve (area = %0.2f) for class %d' % (roc_auc[i], i))

    # Format Plot display
    plt.plot([0, 1], [0, 1], 'k--', lw=2)
    plt.xlim([0.0, 1.0])
    plt.ylim([0.0, 1.05])
    plt.xlabel('False Positive Rate')
    plt.ylabel('True Positive Rate')
    plt.title(f'ROC AUC for {model_name}')
    plt.legend(loc="lower right")

    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    eval_path    = os.path.join(EVAL_PATH,"Models")
    eval_path_dt = f"{DATETIME}_{model_name}"
       
    plt.savefig(os.path.join(eval_path,model_name,f"{model_name}_ROC_AUC.png"))
    plt.close()

    return 

# =/ plot_roc_auc /= #

# ---------------------------------------------------------------------------- #
# Function  : plot_loss_acc 
# Arguments : history,save_location
# Returns   : n/a
#
# Description:  Plot Loss accuracy graphs of trained model
#               
#              
# ---------------------------------------------------------------------------- # 
def plot_loss_acc(history,model_name):
   
    print("Plotting loss and accuracy...")

    acc      = history.history['acc']
    val_acc  = history.history['val_acc']
    loss     = history.history['loss']
    val_loss = history.history['val_loss']
    epochs   = range(1, len(acc) + 1)

    # Create subplots
    plt.figure(figsize=(12, 6))

    # Subplot for accuracy
    plt.subplot(1, 2, 1)
    plt.plot(epochs, acc, 'bo', label='Training acc')
    plt.plot(epochs, val_acc, 'b', label='Validation acc')
    plt.title('Training and validation accuracy')
    plt.legend()

    # Subplot for loss
    plt.subplot(1, 2, 2)
    plt.plot(epochs, loss, 'bo', label='Training loss')
    plt.plot(epochs, val_loss, 'b', label='Validation loss')
    plt.title('Training and validation loss')
    plt.legend()

    print("done...")

    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    eval_path    = os.path.join(EVAL_PATH,"Models")
    eval_path_dt = f"{DATETIME}_{model_name}"

    plt.savefig(os.path.join(eval_path,model_name,f"{model_name}_Loss_Accuracy.png"))
    plt.close()

    return 

# =/ plot_loss_acc /= #

# ---------------------------------------------------------------------------- #
# Function  : plot_tsne 
# Arguments : X,y,save_location
# Returns   : n/a
#
# Description:  Plot t-SNE for dataset
#               
#              
# ---------------------------------------------------------------------------- # 
def plot_tsne(X,y_encoded,model_name):

    # Initialize t-SNE
    #tsne = TSNE(n_components=2, random_state=42, perplexity=50, n_jobs=-1)
    tsne = TSNE(n_components=2, n_jobs=-1)

    # Run t-SNE get the transformed 2D representation
    X_tsne_2d = tsne.fit_transform(X)

    # Scatter plot for each class label
    plt.figure(figsize=(8, 6))

    for i, label in enumerate(np.unique(y_encoded)):
       plt.scatter(X_tsne_2d[y_encoded == i, 0], X_tsne_2d[y_encoded == i, 1], label=label)

    plt.legend()
    plt.xlabel('t-SNE feature 1')
    plt.ylabel('t-SNE feature 2')
    plt.title('2D t-SNE on Dataset')

    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    eval_path    = os.path.join(EVAL_PATH,"Models")
    eval_path_dt = f"{DATETIME}_{model_name}"

    plt.savefig(os.path.join(eval_path,model_name,f"{model_name}_tsne.png"))
    plt.close()

    return 
# =/ plot-tsne /= #

# ---------------------------------------------------------------------------- #
# Function  : plot_umap 
# Arguments : X,y,save_location
# Returns   : n/a
#
# Description:  Plot UMAP of dataset
#               
#              
# ---------------------------------------------------------------------------- # 
def plot_umap(X,y_encoded,model_name):

    umap_model = UMAP(n_neighbors=50, min_dist=1,n_components=2)

    # Run UMAP and get the transformed 2D representation
    X_umap_2d = umap_model.fit_transform(X)

    # Scatter plot for each class label
    for i, label in enumerate(np.unique(y_encoded)):
       plt.scatter(X_umap_2d[y_encoded == i, 0], X_umap_2d[y_encoded == i, 1], label=label)

    # Format and save plot
    #plt.legend()
    plt.xlabel('UMAP feature 1')
    plt.ylabel('UMAP feature 2')
    plt.title('2D UMAP on Dataset')

    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    eval_path    = os.path.join(EVAL_PATH,"Models")
    eval_path_dt = f"{DATETIME}_{model_name}"

    plt.savefig(os.path.join(eval_path,model_name,f"{model_name}_umap.png"))
    plt.close()

    return 
# =/ plot_umap /= #

# ---------------------------------------------------------------------------- #
# Function  : write_metrics 
# Arguments : y_test,y_test_pred,y_train,y_train_pred,txt_location
# Returns   : n/a
#
# Description:  Generate and save accuracy and classification report of model.
#               
#              
# ---------------------------------------------------------------------------- # 
def write_metrics(y_test,y_test_pred,y_train,y_train_pred,model_name):

    # Calculate and print test accuracy
    test_accuracy = accuracy_score(y_test, y_test_pred)

    # Calculate and print train accuracy
    train_accuracy = accuracy_score(y_train, y_train_pred)

    # Calculate and print classification report
    classification_report_str = classification_report(y_test, y_test_pred, target_names=['1', '2', '3', '4', '5','6','7','8','9','10','11','12'])

    eval_path    = os.path.join(EVAL_PATH,"Models")
    eval_path_dt = f"{DATETIME}_{model_name}"
    final_path   = os.path.join(eval_path,model_name,"Metrics.txt")   

    # Write to file
    with open(final_path, 'w') as file:
       file.write("test Accuracy: %.2f%%" % (test_accuracy * 100.0))
       file.write("train Accuracy: %.2f%%" % (train_accuracy * 100.0))
       file.write("\n\n\n")
       file.write(classification_report_str)

    return 
# =/ write_metrics /= #

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

    print("Preprocessing data...")
    # Dataframe to store entire dataset
    full_dataset = pd.DataFrame()

    # Load CSV files from each region and concatenate them
    for region in range(1,N_REGIONS + 1):

        region_dataset = load_csv_files(os.path.join(region_path, f"R{region}"))
        full_dataset   = pd.concat([full_dataset, region_dataset], ignore_index=True)

    # Handling missing values by dropping rows with missing values
    full_dataset.dropna(inplace=True)

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
    
    prune_low_magnitude = tfmot.sparsity.keras.prune_low_magnitude
    
    pruning_params_sparsity_0_5 = {'pruning_schedule': tfmot.sparsity.keras.ConstantSparsity(target_sparsity=0.5,begin_step=0,frequency=100)}
    pruning_params_2_by_4   = { 'sparsity_m_by_n' : (2,4),}

    print("Creating the model...")

    model = Sequential()

    #Input layer neurons (number of features)
    #model.add(Dense(units=1524, input_dim=1524, activation='relu',name="pruning_sparsity_0_5"))
    #prune_low_magnitude(pruning_sparsity_0_5,**pruning_params_sparsity_0_5)
    ##Hidden layers (you can adjust the number of layers and neurons)
    #model.add(Dense(units=256, activation='relu'))
    #model.add(Dropout(0.2))
    #model.add(Dense(units=128, activation='relu'))
    ##dropout layer
    ##Output layer
    #model.add(Dense(units=12, activation='softmax'))

    model = Sequential([
        prune_low_magnitude(
            Dense(1524,input_dim=1524,activation='relu',name="pruning_sparsity_0_5"),
            **pruning_params_sparsity_0_5),
        prune_low_magnitude(
            Dense(units=256,activation='relu'),
            **pruning_params_sparsity_0_5),
        Dropout(0.2),
        prune_low_magnitude(
            Dense(units=128,activation='relu'),
            **pruning_params_sparsity_0_5),
        Dense(units=12,activation='softmax')])


    #Compile the model
    print("Compiling the model...")

    model.compile(optimizer='adam', loss='sparse_categorical_crossentropy', metrics=['acc'])
    
    # ----------------------------------- #
    #  Train the model
    # ----------------------------------- #
    
    print("Training the model...")

    history = model.fit(X_train_scaled, y_train, epochs=3, batch_size=64, validation_data =(X_test_scaled, y_test), verbose=1,callbacks=tfmot.sparsity.keras.UpdatePruningStep())
    
    model.summary()
    # ----------------------------------- #
    #  Model Prediction
    # ----------------------------------- #
    
    loss, accuracy = model.evaluate(X_test_scaled, y_test, verbose=1)

    # Now you can use loaded_model for predictions without retraining
    # Example:

    y_test_pred = model.predict(X_test_scaled)

    y_test_pred = np.array(y_test_pred)
    predicted_classes = np.argmax(y_test_pred, axis=1)

    y_train_pred = model.predict(X_train_scaled)
    y_train_pred = np.array(y_train_pred)

    predicted_classes_train = np.argmax(y_train_pred, axis=1)
    predicted_classes = np.argmax(y_test_pred, axis=1)
    
    # ----------------------------------- #
    #  Evaluate Model
    # ----------------------------------- #
    
    print("Model predictions done \n gathering metrics from model now...")

    plot_confusion_matrix(y_test, predicted_classes, f"Test Confusion Matrix for {model_name}",model_name)

    plot_loss_acc(history, model_name)

    write_metrics(y_test, predicted_classes, y_train, predicted_classes_train, model_name)

    plot_roc_auc(y_test, y_test_pred, model_name)

    #plot_tsne(X,y_encoded,model_name)
    
    #plot_umap(X,y_encoded,model_name)
    # ----------------------------------- #
    #  Save the model
    # ----------------------------------- #

    model = tfmot.sparsity.keras.strip_pruning(model)

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
    converter.optimizations = [tf.lite.Optimize.DEFAULT]
    tflite_model = converter.convert()
    
    # ----------------------------------- #
    #  Look into 8_bit weights
    # ----------------------------------- #
    
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
    














