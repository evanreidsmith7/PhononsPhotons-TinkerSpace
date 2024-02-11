import serial
import numpy as np
import matplotlib.pyplot as plt
import os

# Macros
ADC_CHANNELS = 3
FFT_BATCH_SIZE = 512
REGION = 1
ADC_SAMPLE_FREQUENCY = 240000
COLLECT_DATA = False

# Declare path to data dir
region_dir = 'DataExtraction\Raw'
region_dir = os.path.join(region_dir, f'Region_{REGION}_Data.csv')

# Hard coded COM port selection
com_port = serial.Serial(port='COM13', baudrate=4000000, timeout=20.0)

# Make region dir

# Write header to CSV files
csv_header = ["Freq", "Ch1_Mag", "Ch2_Mag", "Ch3_Mag", "Region"]

reg1_dir = os.path.join(region_dir, f'Region_{REGION}_Data.csv')

try:
    np.savetxt(reg1_dir, [csv_header], delimiter=",", fmt='%s')
except Exception as e:
    print(f"Error writing header: {e}")

# Setup figure for displaying fft data.
plt.figure()
plt.ylim([-100, 10])
plt.xlabel("Frequency (kHz)")
plt.ylabel("Magnitude (dBV)")
plt.title("")
plt.grid(True)

x_freqs = 2 * 200 / FFT_BATCH_SIZE * np.arange(FFT_BATCH_SIZE // 2)
start_bytes = 0

# Init variables
noise_floor = np.full(FFT_BATCH_SIZE // 2, -100)
noise_floor_samples = 0
noise_floor_offset_db = 6

while True:
    # sync with data
    start_bytes = 0
    while start_bytes < 4:
        start_byte = com_port.read(1)[0]
        print(start_byte)
        if start_byte == 0x55:
            start_bytes += 1
        else:
            start_bytes = 0

    fft_data = np.frombuffer(com_port.read(ADC_CHANNELS * FFT_BATCH_SIZE), dtype=np.float32)
    fft_one = fft_data[0:256]
    fft_two = fft_data[256:512]
    fft_three = fft_data[512:768]

    if COLLECT_DATA:
        # Transpose data
        fft_one_transposed = fft_one.T
        fft_two_transposed = fft_two.T
        fft_three_transposed = fft_three.T

        # Write channel data to CSV
        for idx in range(len(fft_one_transposed)):
            # Calc bin freq
            freq = (idx - 1) * (ADC_SAMPLE_FREQUENCY / 2) / (FFT_BATCH_SIZE / 2)

            row = [freq, fft_one_transposed[idx], fft_two_transposed[idx], fft_three_transposed[idx], REGION]
            np.savetxt(reg1_dir, [row], delimiter=",", fmt='%f', header='', comments='', mode='a')

    if noise_floor_samples < 20:
        for index in range(FFT_BATCH_SIZE // 2):
            if fft_one[index] > noise_floor[index]:
                noise_floor[index] = fft_one[index]
            if fft_two[index] > noise_floor[index]:
                noise_floor[index] = fft_two[index]
        noise_floor_samples += 1

    plt.clf()
    plt.plot(x_freqs, fft_one[2:256], "-r")
    plt.plot(x_freqs, fft_two[2:256], "-b")
    plt.plot(x_freqs, fft_three[2:256], "-g")
    plt.plot(x_freqs, noise_floor[2:256] + 6, "--k")
    plt.grid(True)
    plt.draw()
    plt.pause(0.01)

# Close the serial port
com_port.close()
