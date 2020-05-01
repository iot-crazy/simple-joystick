# Simple Joystick Tutorial

This simple tutorial for arduino will show you how to read the values from a thumb joystick. Due to the nature of ADC (Analogue to Digital Conversion) and depending upon the sensitivity of your device, the values may be seeen to be constantly changing. This tutorial includes solution to 'smooth' those readings to make the joystick more friendly to our projects.

## Getting Started

These instructions will get you a copy of the project up and running on your local machine for development and testing purposes.

### Prerequisites

You will need:
1. An arduino device with at least 2 analogue inputs and 1 digital input
2. A thumb joystick for arduino. Many are available online
3. A 10kΩ resistor (if you want to use the joystick button)
4. Connecting wires

The ESP8266 only has a single ADC input and is therefore not suitable for this demo. See our multiplexing tutorial for extending the capabilities of your device. 

You will already know:
1. How to use the Arduino IDE (or IDE of your choice)
2. How to upload sketches / code to your device
3. How to open the serial monitor


### Installing

1. Clone the repo to your local computer, or copy the .ino file.
2. Connect the x & y axes of your joystick to the ADC pins on your arduino
3. Connect the button to a free digital pin
4. Set the pin numbers
5. Compile and upload to your device.
6. Open the serial monitor to view the values
7. Wiggle your stick and see the values change


## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
