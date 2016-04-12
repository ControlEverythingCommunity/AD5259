# Distributed with a free-will license.
# Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
# AD5259
# This code is designed to work with the AD5259_I2CPOT_10K I2C Mini Module available from ControlEverything.com.
# https://www.controleverything.com/content/Potentiometers?sku=AD5259_I2CPOT_10K#tabs-0-product_tabset-2

import smbus
import time

# Get I2C bus
bus = smbus.SMBus(1)

# AD5259 address, 0x18(24)
# Send command byte, 0x00(00)
#		0x80(128)	Input resistance value
bus.write_i2c_block_data(0x18, 0x00, [0x80])

time.sleep(0.5)

# AD5259 address, 0x18(24)
# Read data back from 0x00(00), 1 byte
data = bus.read_byte_data(0x18, 0x00)

# Convert the data
resistance = (data / 256.0 ) * 10.0

# Output data to screen
print "Resistance : %.2f K" %resistance
