import streamlit as st
import pandas as pd
import time
import numpy as np

# streamlit settings
time_list = []
value1_list = []
value2_list = []
value3_list = []
chart = st.line_chart()

# ------- read serial terminal code -------
import serial
import re

# Set up the serial connection
serial_port = '/dev/cu.usbserial-2110'  # Replace with your Arduino's port
baud_rate = 115200
ser = serial.Serial(serial_port, baud_rate)

# Read values from the serial monitor
while True:
    line = ser.readline().decode().strip()
    match = re.findall(r'Roll rate \[°/s\]=\s*([-+]?\d*\.\d+|\d+)\s+Pitch Rate \[°/s\]=\s*([-+]?\d*\.\d+|\d+)\s+Yaw Rate \[°/s\]=\s*([-+]?\d*\.\d+|\d+)', line)
    if match:
        roll, pitch, yaw = match[0]
        print(f"Roll: {roll}, Pitch: {pitch}, Yaw: {yaw}")
        
# ------- end read serial terminal code -------

#  ------- streamlit code -------
    # Initialize empty lists to store data
    new_time = time.strftime('%H:%M:%S')
    new_value1 = roll
    new_value2 = pitch
    new_value3 = yaw

    # Append the new data to the lists
    if len(value1_list) > 20:
        time_list.pop(0)
        value1_list.pop(0)
        value2_list.pop(0)
        value3_list.pop(0)
    time_list.append(new_time)
    value1_list.append(new_value1)
    value2_list.append(new_value2)
    value3_list.append(new_value3)

    data = pd.DataFrame({
    'Time': time_list,
    'roll': value1_list,
    'pitch': value2_list,
    'yaw': value3_list
    })
    
    chart.line_chart(data.set_index('Time'))

