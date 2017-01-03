int redPin = 11;
int greenPin = 10;
int bluePin = 9;

void setup() {
  int actuator = 3;
  int interval = 1000;
  pinMode(redPin, OUTPUT);
  pinMode(greenPin, OUTPUT);
  pinMode(bluePin, OUTPUT);  
  pinMode(actuator, OUTPUT);
  analogWrite(greenPin, 255);
  delay(interval);
  
  for(int i = 0; i < 3; i++) {
    digitalWrite(actuator, HIGH);
    analogWrite(greenPin, 0);
    analogWrite(redPin, 255);
    delay(interval);
    digitalWrite(actuator, LOW);
    analogWrite(redPin, 0);
    analogWrite(greenPin, 255);
    delay(interval);
  }
  
//digitalWrite(actuator, HIGH);
//delay(3000);
//digitalWrite(actuator, LOW);
}

void loop() {
  setColor(255, 0, 0);  // red
  delay(1000);
  setColor(0, 255, 0);  // green
  delay(1000);
  setColor(0, 0, 255);  // blue
  delay(1000);
  setColor(255, 255, 0);// yellow
  delay(1000);  
  setColor(80, 0, 80);  // purple
  delay(1000);
  setColor(0, 255, 255);// aqua
  delay(1000);
}

void setColor(int red, int green, int blue) {
  #ifdef COMMON_ANODE
    red = 255 - red;
    green = 255 - green;
    blue = 255 - blue;
  #endif
  analogWrite(redPin, red);
  analogWrite(greenPin, green);
  analogWrite(bluePin, blue);  
}
