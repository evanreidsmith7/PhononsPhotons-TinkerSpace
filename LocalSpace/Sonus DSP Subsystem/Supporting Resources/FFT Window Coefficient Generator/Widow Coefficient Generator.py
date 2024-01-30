# this python script calculates window coefficients for given fft batch sizes,
# console output is direct copy-paste into a c array definition

import math

FFT_BATCH_SIZE = 1024

index = 0

print("static const float HANN_WINDOW_COEFF[FFT_BATCH_SIZE] = {"),
while index < FFT_BATCH_SIZE:
    print(math.pow(math.sin(math.pi*index/(FFT_BATCH_SIZE-1)), 2)),
    
    if index < FFT_BATCH_SIZE - 1:
        print(","),
    
    index += 1
    
print ("};")

