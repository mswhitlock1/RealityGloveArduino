/*
  ReadAnalogVoltage

  Reads an analog input on pin 0, converts it to voltage, and prints the result to the Serial Monitor.
  Graphical representation is available using Serial Plotter (Tools > Serial Plotter menu).
  Attach the center pin of a potentiometer to pin A0, and the outside pins to +5V and ground.

  This example code is in the public domain.

  http://www.arduino.cc/en/Tutorial/ReadAnalogVoltage
*/
int rotatingIndex;
int indexValues[20];
int middleValues[20];
int ringValues[20];
int pinkyValues[20];

// the setup routine runs once when you press reset:
void setup() {
  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);

  //configure pins as an input and enable the internal pull-up resistor
  pinMode(2, INPUT_PULLUP);
  pinMode(3, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(5, INPUT_PULLUP);

  rotatingIndex = 0;
}

// the loop routine runs over and over again forever:
void loop() {
  // Read Digital Output values at each finger
  int indexSensorValue = digitalRead(2);
  int middleSensorValue = digitalRead(3);
  int ringSensorValue = digitalRead(4);
  int pinkySensorValue = digitalRead(5);

  if (arraySum(indexValues) < 17) {
    Serial.print("index ");
  }
  if (arraySum(middleValues) < 17) {
    Serial.print("middle ");
  }
  if (arraySum(ringValues) < 17) {
    Serial.print("ring ");
  }
  if (arraySum(pinkyValues) < 17) {
    Serial.print("pinky ");
  }
  Serial.println ();

  indexValues[rotatingIndex] = indexSensorValue;
  middleValues[rotatingIndex] = middleSensorValue;
  ringValues[rotatingIndex] = ringSensorValue;
  pinkyValues[rotatingIndex] = pinkySensorValue;

  rotatingIndex = rotatingIndex + 1;
  if (rotatingIndex == 20) {
    rotatingIndex = 0;
  }
}

int arraySum (int arr[]) {
  int sum = 0;
  for (int i = 0; i < 20; i++) {
    sum += arr[i];
  }
  return sum;
}
