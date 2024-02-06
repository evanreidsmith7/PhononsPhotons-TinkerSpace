import tensorflow as tf
import os

converter = tf.lite.TFLiteConverter.from_saved_model(os.getcwd())
tflite_model = converter.convert()

with open('model.tflite','wb') as f:
    f.write(tflite_model)

