


# DHT12
Provides an Arduino library for reading DHT12 sensor data over I2C.

## Table of Contents

* [DHT12](#dht12)
* [Table of Contents](#table_of_contents)
* [Summary](#summary)
* [Installation](#installation)
* [Usage](#usage)
* [Methods](#methods)

 * [void Dht12()](#methods)
 * [void begin()](#methods)
 * [void read(float& temperature, float& humidity)](#methods)
* [Contributing](#contributing)
* [History](#history)
* [Credits](#credits)
* [License](#license)
<snippet>
<content>

## Summary


## Installation

To use this library download the zip file, uncompress it to a folder named DHT12. Move the folder to {Arduino Path}/libraries.

## Usage

Include the library at the top of your Arduino script. `#include <dht12>`
Create a global or local variable. `Dht12 sensor(SDA_PIN, SCL_PIN)`
In your start up call `sensor.begin()`.
Read the temperature, humidity.

`float temp, hum`
`sensor.read(temp, hum)`

## Methods


#### void Dht12(int sda, int scl)

  Constructor. 
  sda and scl - pins for i2c interface.

#### void begin()

  Method used at start up to initialize the class. Starts the I2C interface. Can be called again to re-initialize the mode settings.

#### bool read(float& temperature, float& humidity)

  Read the data from the DHT12.
  Return: None, however, temp and humidity are changed.

    * Temperature: float, reference
      values: reference to storage float for temperature

    * Humidity: float, reference
      values: reference to storage float for humidity

## Contributing

1. Fork the project.
2. Create your feature branch: `git checkout -b my-new-feature`
3. Commit your changes: `git commit -am 'Add some feature'`
4. Push to the branch: `git push origin my-new-feature`
5. Submit a pull request.

## History

- Oct 10, 2017 - Version 1.0.0 released.

## Credits

Written by Sergey Maslov, 2017.

## License

GNU GPL, see License.txt
</content>
</snippet>
