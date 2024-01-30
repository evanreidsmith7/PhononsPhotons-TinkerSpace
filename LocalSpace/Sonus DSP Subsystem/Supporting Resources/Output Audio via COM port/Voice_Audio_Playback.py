import serial
import pyaudio

# **** There is no synchronization, on the event that it starts with the wrong
#        byte of a sample, you will hear nothing but static
#        Restart the script to resolve this

AUDIO_SAMPLES_PER_BLOCK = 40;

# "COMxx" should be set to your stlink virtual com port device ID
com_port = serial.Serial(port='COM17', baudrate=4000000, timeout=2)
audio_port = pyaudio.PyAudio( )
audio_stream = audio_port.open(format=pyaudio.paInt16,
                               channels=1,
                               rate=16000,
                               output=True,
                               frames_per_buffer=60)


while 1:
    audio_data_bytes = com_port.read(AUDIO_SAMPLES_PER_BLOCK * 2)
    audio_stream.write(audio_data_bytes)

# TODO - Add quit on ESC key, as is the shell must be closed or restarted to exit