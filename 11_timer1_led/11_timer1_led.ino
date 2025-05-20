#include <TimerOne.h>

const int LED = 5;
int ledFlag = 0;

void timerIsr(void)
{
  if(ledFlag == 0){
    digitalWrite(LED, HIGH); 
    ledFlag = 1;
  }
  else if(ledFlag == 1){
    digitalWrite(LED, LOW); 
    ledFlag = 0;
  }
}

void setup() {
  // put your setup code here, to run once:
  pinMode(LED, OUTPUT);

  Timer1.initialize(1000000);
  //Timer1.pwm(LED, 0); // Timer1을 이용하여 PWM 기능을 사용하는 경우 설정
  Timer1.attachInterrupt(timerIsr); // Timer1 인터럽트 기능을 사용하는 경우 설정
}

void loop() {
  // put your main code here, to run repeatedly:
  // for(int i=0; i<1024; i++)
  // {
  //   Timer1.setPwmDuty(LED, i);
  //   delay(1);
  // }
}
