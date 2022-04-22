### SparkFun MMA8452Q 3-Axis Accelerometer Particle Library

A firmware library for the SparkFun's [MMA8452Q 3-Axis Accelerometer](https://www.sparkfun.com/products/12756).

[![MMA8452Q 3-Axis Accelerometer](https://cdn.sparkfun.com//assets/parts/9/5/1/5/12756-00.jpg)](https://www.sparkfun.com/products/12756)
About
-------------------

The MMA8452Q is an I2C-based 3-axis accelerometer. It has user selectable full scales of ±2g/±4g/±8g with high pass filtered data as well as non filtered data available real-time. Unique features include programmable interrupts, tap-detection, and orientation detection.

Repository Contents
-------------------

* **/firmware** - Source files for the library (.cpp, .h).
* **/firmware/examples** - Example sketches for the library (.cpp). Run these from the Particle IDE. 
* **spark.json** - General library properties for the Particle library manager. 

Example Usage
-------------------

#### Create an MMA8452Q 3-Axis Accelerometer Object & Initialize

To begin, create an MMA8452Q 3-Axis Accelerometer class object. This'll often go in the global section of the code:

	//////////////////////////////
	// MMA8452Q Object Creation //
	//////////////////////////////
	MMA8452Q accel; // This creates an MMA8452Q object, which we'll use to interact with the sensor

To initialize the sensor, call the `begin([range], [odr])` function, where `[range]` is the full-scale range of the sensor and `[odr]` is the output data rate:

	void setup()
	{
		...
		accel.begin(SCALE_2G, ODR_1); // Set up accel with +/-2g range, and slowest (1Hz) ODR
		...
	}

The full-scale range can be: `SCALE_2G`, `SCALE_4G`, or `SCALE_8G` (2, 4, or 8g).

The output-data rate (ODR) can be: `ODR_800`, `ODR_400`, `ODR_200`, `ODR_100`, `ODR_50`, `ODR_12`, `ODR_6` or `ODR_1` (800, 400, 200, 100, 50, 12, 6, or 1 Hz).

#### Update and Read Acceleration Values

All three of the accelerometer values are read in one fell swoop with the `read()` function:

	accel.read();

Once read, the library updates six class variables: `x`, `y`, `z` -- the "raw" 12-bit values from the accelerometer -- and `cx`, `cy`, and `cz`, the calculated accelerations in _g_.

	Serial.println("X: " + String(accel.x) + " | " + String(accel.cx, 2) + " g");
	Serial.println("Y: " + String(accel.y) + " | " + String(accel.cy, 2) + " g");
	Serial.println("Z: " + String(accel.z) + " | " + String(accel.cz, 2) + " g");

Recommended Components
-------------------

* [MMA8452Q 3-Axis Accelerometer](https://www.sparkfun.com/products/12756)
* [Particle Photon](https://www.sparkfun.com/products/13345) or [SparkFun Photon RedBoard](https://www.sparkfun.com/products/13321)

License Information
-------------------

This product is _**open source**_! 

Please review the LICENSE.md file for license information. 

If you have any questions or concerns on licensing, please contact techsupport@sparkfun.com.

Distributed as-is; no warranty is given.

- Your friends at SparkFun.