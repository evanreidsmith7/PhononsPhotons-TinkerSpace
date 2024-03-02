import serial
import datetime
import wave


# ask the user for the length of the audio in seconds
length = int(input("Enter the length of the recording in seconds: "))


# set the WAV file parameters
channels = 1
sample_rate = 16000

# Specify the COM port and baud rate
comPort = "COM13"
baudRate = 115200

# Create a new SerialPort object
serialPort = serial.Serial(comPort, baudRate)




try:
    while True:
        data = serialPort.readline().decode('utf-8').strip()
        print(data)
except serial.SerialException as e:
    print(f"Error: {e}")
except KeyboardInterrupt:
    print("Serial reading terminated by the user.")
finally:
    serialPort.close()







'''
for i in range(length*sample_rate):
   data = ser.read(4)
   print(data)



# get the current date and time
now = datetime.datetime.now()

# create a filename with a datetimestamp
filename = "recording_{}.wav".format(now.strftime("%Y-%m-%d_%H-%M-%S"))


sample_width = 2 # 2 bytes per sample

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
'''