import pandas as pd
import numpy as np
import tensorflow as tf
import os

# Load the TFLite model and allocate tensors.
interpreter = tf.lite.Interpreter(model_path=os.path.join(os.getcwd(),"Output/Models/ann_1524/03_25_120900_ann_1524.tflite"))
interpreter.allocate_tensors()

# Get input and output tensors.
input_details = interpreter.get_input_details()
output_details = interpreter.get_output_details()

print(input_details)
df = pd.DataFrame()
df = pd.read_csv(os.path.join(os.getcwd(),"Datasets/12Region_Dset/R7/Region_7_data_100_Vol_far.csv"))
df = df.iloc[:,:-1]
df = df.astype('float32')
input_data = df.iloc[0:10]

input_data = input_data.astype('float32')
input_data = input_data.to_numpy()
for i in input_data:
    li = []
    li.append(i)
    # Test the model on random input data.
    input_shape = input_details[0]['shape']
    input_data = np.array(np.random.random_sample(input_shape), dtype=np.float32)

    print(type(input_data))
    interpreter.set_tensor(input_details[0]['index'], li)

    interpreter.invoke()

    # The function `get_tensor()` returns a copy of the tensor data.
    # Use `tensor()` in order to get a pointer to the tensor.
    output_data = interpreter.get_tensor(output_details[0]['index'])
    print(output_data)
