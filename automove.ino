int stepperDelay;
int k = 0;

void setup() {

  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  stepperDelay = 4;
}
int inByte = 0;

void loop() {
	k=53;
    for(int i = 0; i < k; i++){
      forward();
    }
	delay(10000); 
    for(int i = 0; i < k; i++){
      backward();
    }
	delay(10000); 
    

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