const int potPin = A0;   
const int motorPin = 9;    

void setup() {
  Serial.begin(9600);
  pinMode(motorPin, OUTPUT);
}

void loop() {
  int potValue = analogRead(potPin);      
  int pwmValue = map(potValue, 0, 1023, 0, 255);

  analogWrite(motorPin, pwmValue);    
  Serial.print("Pot: ");
  Serial.println(potValue);
  Serial.print("PWM: ");
  Serial.println(pwmValue);
  delay(1000);
}