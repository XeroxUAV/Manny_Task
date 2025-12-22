void setup(){
  pinMode(3,OUTPUT);
}

void loop() {
  for(int brightness=0; brightness<=255; brightness++)
  {
    analogWrite(3,brightness);
    delay(100);
  }
  for(int brightness=255; brightness>=0; brightness--)
  {
    analogWrite(3,brightness);
    delay(100);
  }
}
