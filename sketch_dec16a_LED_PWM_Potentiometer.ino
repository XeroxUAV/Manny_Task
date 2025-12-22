void setup(){
  pinMode(3,OUTPUT);
  Serial.begin(9600);
}

void loop() {
    int LEDValue = analogRead(A0);
    int brightness = map(LEDValue,0,1023,0,255);
    analogWrite(3,brightness);
    Serial.println(brightness);
}
