const int LED[6] = {3, 5, 6, 9, 10, 11};

void setup() {
  // put your setup code here, to run once:
  //analogWrite(LED, 225);


}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 6; i++)
  {
      for(int j = 0; j < 256; j++)
      {
          analogWrite(LED[i], j);
          delay(5);
      }
      for(int k = 255; k >= 0; k--)
      {
          analogWrite(LED[i], k);
          delay(5);
      }
      analogWrite(LED[i], 0);
  }

}
