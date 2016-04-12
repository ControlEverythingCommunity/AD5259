// Distributed with a free-will license.
// Use it any way you want, profit or free, provided it fits in the licenses of its associated works.
// AD5259
// This code is designed to work with the AD5259_I2CPOT_10K I2C Mini Module available from ControlEverything.com.
// https://www.controleverything.com/content/Potentiometers?sku=AD5259_I2CPOT_10K#tabs-0-product_tabset-2

import com.pi4j.io.i2c.I2CBus;
import com.pi4j.io.i2c.I2CDevice;
import com.pi4j.io.i2c.I2CFactory;
import java.io.IOException;

public class AD5259
{
	public static void main(String args[]) throws Exception
	{
		// Create I2C bus
		I2CBus Bus = I2CFactory.getInstance(I2CBus.BUS_1);
		// Get I2C device, AD5259 I2C address is 0x18(24)
		I2CDevice device = Bus.getDevice(0x18);
		
		// Send command byte, 0x00(00)
		// Input resistance value
		byte[] data = new byte[1];
		data[0] = (byte)0x80;
		device.write(0x00, data, 0, 1);
		Thread.sleep(500);
		
		// Read data back from 0x00(00), 1 byte
		byte data1 = (byte)device.read(0x00);
		
		// Convert the data
		double resistance = ((data1 & 0xFF )/ 256.0) * 10.0;
		
		// Output data to screen
		System.out.printf("Resistance : %.2f K", resistance);
	}
}
