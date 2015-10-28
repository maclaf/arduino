/*
  Blink
  Turns on an LED on for one second, then off for one second, repeatedly.

  Most Arduinos have an on-board LED you can control. On the Uno and
  Leonardo, it is attached to digital pin 13. If you're unsure what
  pin the on-board LED is connected to on your Arduino model, check
  the documentation at http://arduino.cc

  This example code is in the public domain.

  modified 8 May 2014
  by Scott Fitzgerald
 */


int stepperDelay;
int k = 0;

// tdhe setup function runs once when you press reset or power the board
void setup() {

  Serial.begin(9600);
  while (!Serial) {
    ;
  }
  Serial.println("ASCII Table ~ Character Map");
  Serial.print(", dec: ");
  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  stepperDelay = 5;
}
int inByte = 0;
// the loop function runs over and over again forever
void loop() {
  if (Serial.available() > 0) {
    inByte = Serial.read();
    int steps = Serial.parseInt();
    if (inByte == 'r') {
      for (int i = 0; i < steps; i++) {
        forward();
      }
    } else {
      for (int i = 0; i < steps; i++) {
        backward();
      }
    }




    Serial.println(steps);

  }
  //  k=200;
  //  for(int i = 0; i < k; i++){
  //    forward();
  //  }
  //  for(int i = 0; i < k; i++){
  //    backward();
  //  }

}
void forward() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(12 - i, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(stepperDelay);              // wait for a second
    digitalWrite(12 - i, LOW);  // turn the LED off by making the voltage LOW
    delay(stepperDelay);              // wait for a second
  }
}
void backward() {
  for (int i = 0; i < 4; i++) {
    digitalWrite(9 + i, HIGH); // turn the LED on (HIGH is the voltage level)
    delay(stepperDelay);              // wait for a second
    digitalWrite(9 + i, LOW);  // turn the LED off by making the voltage LOW
    delay(stepperDelay);              // wait for a second
  }
}