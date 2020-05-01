// IoT Crazy 2020
// Simple joystick tutorial with smoothing

// Which pins the joystick is connected to
int JoyStick_X = 36; // x
int JoyStick_Y = 39; // y
int JoyStick_Z = 35; // switch - remember the pullup resistor!

int prevx, prevy, prevbtn = 0; // previous states or each joystick input, default to zero
int minChange = 20; // minimum amount of change that must be seen to determine that the stick has moved
int numSamples = 20; // how many samples to take when reading the joystick
float stickMax = 4290; // the maximum expected value from joystick axes 
float stickMin = 0; // the minimum expected value from joystick axes
float stickMidX = 1913; // the middle value of the X axis - found my running the program and looking at the output
float stickMidY = 1959;  // the middle value of the Y axis - found my running the program and looking at the output


void setup() {
  Serial.begin(115200);
  delay(10);
  pinMode(JoyStick_Z, INPUT); 
  pinMode(JoyStick_X, INPUT); 
  pinMode(JoyStick_Y, INPUT); 
}

void loop() {
  int x,y,z,sum_x,sum_y = 0; // start with all values at zero 

  // collect the required number of samples and add to a sum
  for(int i = 0; i<=numSamples; i++)
  {
    sum_x += analogRead(JoyStick_X);
    sum_y += analogRead(JoyStick_Y);
  }

  // find the mean average of the samples
  x = sum_x / numSamples;
  y = sum_y / numSamples;
  z = digitalRead(JoyStick_Z);

  // if the average of either axis is greater than the minimum required change, or the button state has changed, display the values
  if (abs(x - prevx) > minChange || abs(y - prevy) > minChange || z != prevbtn)
  { 
    Serial.printf("Stick: %d,%d Δ: %d,%d / btn:%d \n", x, x, abs(x-prevx), abs(y-prevy), z);

    // save the current values as the new 'previous' value to compare on th next loop
    prevx = x;
    prevy = y;
    prevbtn = z;
  }

}
