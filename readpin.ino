#define TIMEOUT (10000UL)     // Maximum time to wait for serial activity to start

int ledPin = LED_BUILTIN;  // LED connected to digital pin 13
int inPin = 2;    // pushbutton connected to digital pin 7
int val = 0;      // variable to store the read value
int prevVal = -1;      // variable to store the read value

void setup() {
  pinMode(ledPin, OUTPUT);  // sets the digital pin 13 as output
  pinMode(inPin, INPUT_PULLUP);    // sets the digital pin 7 as input

  // start serial
  Serial.begin(9600);
  Serial.flush();
  Serial.println("\n\nStarted CrisisKicker");
}

void loop() {
  val = digitalRead(inPin);   // read the input pin
  if (val != prevVal) {
    if (val == 0) {
      Serial.println("on");
    } else {
      Serial.println("off");
    }
    prevVal = val;
    delay(10);
  } else {

  }
  digitalWrite(ledPin, val);  // sets the LED to the button's value
}
