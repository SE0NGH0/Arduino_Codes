#include <TimerOne.h>
#include <PinChangeInterrupt.h>

const int trig_pin = 11;
const int echo_pin = 12;
int start_flag = 1;
unsigned long echo_duration = 0;

void echoIsr(void){
  static unsigned long echo_begin = 0;
  static unsigned long echo_end = 0;
  unsigned int echo_pin_state = digitalRead(echo_pin);

  if(echo_pin_state == HIGH){
    echo_begin = micros();
  }else{
    echo_end = micros();
    echo_duration = echo_end - echo_begin;
  }
}

void timer1Isr(void){
  start_flag = 1;
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(trig_pin, OUTPUT);
  pinMode(echo_pin, INPUT);

  Timer1.initialize(500000);
  Timer1.attachInterrupt(timer1Isr);
  attachPCINT(digitalPinToPCINT(echo_pin), echoIsr, CHANGE);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(start_flag == 1){
    if(echo_duration == 0){
      digitalWrite(trig_pin, LOW);
      delayMicroseconds(2);
      digitalWrite(trig_pin, HIGH);
      delayMicroseconds(10);
      digitalWrite(trig_pin, LOW);
    }else{
      unsigned long distance = echo_duration / 58;
      Serial.print(distance);
      Serial.println(" cm");
      echo_duration = 0;
      start_flag = 0;
    }
  }
}
