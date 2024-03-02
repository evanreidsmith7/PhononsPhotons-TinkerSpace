import serial
import datetime
import wave

# open a serial connection to the Arduino
ser = serial.Serial('COM13', 115200)

# ask the user for the length of the audio in seconds
length = int(input("Enter the length of the recording in seconds: "))

# get the current date and time
now = datetime.datetime.now()

# create a filename with a datetimestamp
filename = "recording_{}.wav".format(now.strftime("%Y-%m-%d_%H-%M-%S"))

# set the WAV file parameters
channels = 1
sample_width = 2 # 2 bytes per sample
sample_rate = 16000

# open a file for writing the audio data
with wave.open(filename, 'wb') as f:
    # set the WAV file parameters
    f.setnchannels(channels)
    f.setsampwidth(sample_width)
    f.setframerate(sample_rate)

    # read audio data from the serial port and write it to the file
    for i in range(length*sample_rate):
        data = ser.read(2)
        if data:
            f.writeframes(data)

# close the serial connection
ser.close()

print("Recording saved as {}".format(filename))