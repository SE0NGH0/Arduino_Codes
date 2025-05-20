const int BUZZER = 10;

const int note[9] = {-1, 262, 294, 330, 349, 393, 440, 494, 523};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available())
  {
    char userInput = Serial.read();
    if('1' <= userInput && userInput <= '8')
    {
      int num = userInput - '0';

      tone(BUZZER, note[num]);
      delay(500);
    }
  }

  noTone(BUZZER);

}
