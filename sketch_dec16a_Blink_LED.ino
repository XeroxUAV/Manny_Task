void setup() {
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  digitalWrite(4,LOW);
}

void loop() {
  if(digitalRead(4)==HIGH)
  {
    digitalWrite(2,HIGH);
  }
  else
  {
    digitalWrite(2,LOW);
  }
}
