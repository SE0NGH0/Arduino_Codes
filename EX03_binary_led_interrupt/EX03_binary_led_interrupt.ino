#include "PinChangeInterrupt.h"

const int LED[6] = {8, 9, 10, 11, 12, 13};
const int SW_0 = 4;
int cnt = 0;

void SW_0_Pressed(void) {
  cnt++;
}

void setup() {
  // put your setup code here, to run once:
  for(int i = 0; i < 6; i++)
  {
    pinMode(LED[i], OUTPUT);
  } 
  
  attachPCINT(digitalPinToPCINT(SW_0), SW_0_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly: 
  for(int i = 0; i < 6; i++)
  {
      digitalWrite(LED[i], cnt & (0x01 << i) ? HIGH : LOW);
  }
}


