const int LED[8] = {2, 3, 4, 5, 6, 7, 8, 9};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  Serial.println(sizeof(LED));
  Serial.println(sizeof(int));
  
  for(int i = 0; i < (sizeof(LED)/sizeof(int)); i++)
  {
      pinMode(LED[i], OUTPUT);
  }

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < (sizeof(LED)/sizeof(int)); i++)
  {
      for(int i = 0; i < (sizeof(LED)/sizeof(int)); i++)
      {
         digitalWrite(LED[i], LOW);

      }
      digitalWrite(LED[i], HIGH);

      delay(100);
  }

/*
  for(int i = sizeof(LED); i > 0; i--)
  {
      for(int i = sizeof(LED); i > 0; i--)
      {
         digitalWrite(LED[i], LOW);
      }
      digitalWrite(LED[i], HIGH);

      delay(100);
  }
*/

}
