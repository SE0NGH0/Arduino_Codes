const int LED[6] = {3, 5, 6, 9, 10, 11};
int cnt = 0;

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 6; i++)
  {
    pinMode(LED[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 0; i < 6; i++)
  {
      digitalWrite(LED[i], cnt & (0x01<<i) ? HIGH : LOW);
  }

  cnt++;
  delay(1000);

}
