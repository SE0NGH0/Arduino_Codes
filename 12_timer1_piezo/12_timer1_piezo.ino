#include <TimerOne.h>

const int BUZZER = 10;
const int melody[] = {262,294,330,349,393,440,494,523};

void setup() {
  // put your setup code here, to run once:
  Timer1.initialize();
  Timer1.pwm(BUZZER,512);

  for(int note=0; note<8; note++){
    Timer1.setPeriod(1000000/melody[note]);
    delay(500);
  }

   35= map(100,0,2000,0,1023);

  Timer1.setPwmDuty(BUZZER, 0);
}

void loop() {
  // put your main code here, to run repeatedly:

}
