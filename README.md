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

### Notes about thumb joysticks

Many of the cheaper thumb sticks available are also not particularly good quality and we find that the reisitance across the aces are not always linear and also reach min / max values a long way before the end of the stick travel. 
We have also seen that some have a pin labelled '5v', however, some devices, such as the ESP8366 allow a maximum of 3.3v on the ADC pin and voltages above this will cause unexpected results and may damage the device. Please connect the '5v' pin to the appropriate voltage for your ADC device. On the ESP32, we use the 3.3v line.

The button on our stick connects the output pin to GND when pressed and leaves the pin floating when not pressed which resulted in constantly changing values on the digital pin. For this reason we recommend a 10kΩ resistor from the button pin to +ve (we used the 3.3v line again).


### Installing

1. Clone the repo to your local computer, or copy the .ino file.
2. Connect the x & y axes of your joystick to the ADC pins on your arduino
3. Connect the button to a free digital pin
4. Set the pin numbers
5. Compile and upload to your device.
6. Open the serial monitor to view the values
7. Wiggle your stick and see the values change

## Tested On

ESP32 dev kit

Please let us know if you test this on other devices so we can add to the list and acknowledge your contribution!

## Trouble Shooting

### Serial is connected but I don't see any values
1. Are the correct pin numbers in the code? (be careful not to mix up GPIO numbers and physical pin numbers)
2. Is the +ve pin on the joystick connected to the correct voltage to match the analogue pins in use?

### Joystick is not being moved, but values are still changing 
1. Is the pull up resistor connected to the switch pin? The values are output if the switch is pressed even if the stick hasn't moved far enough
2. Is the device connected to a 'noisy' power supply which is causing votlage fluctuations, or are other nearby devices possibly causing interferrence
3. Joystick quality or even simple loose connections can also cause fluctuationsin the votlage reaching the ADC pins

## License

This project is licensed under the MIT License - see the [LICENSE.md](LICENSE.md) file for details
