int motor = 9;

void setup() {
  Serial.begin(9600);
  pinMode(motor, OUTPUT);
}

void loop() {
  for(int i=255; i<=0; i--)
  {
    analogWrite(motor, i);
    Serial.println(i);
    delay(100);
  }
  delay(1500);
  //Calibrated
  for(int i=0; i<=255; i++)
  {
    analogWrite(motor, i);
    Serial.println(i);
    delay(100);
  }
  delay(1500);
}