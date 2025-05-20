#include <Arduino.h>
#include <TimerOne.h>

// ECHO pin
#define ECHO_INPUT      2
// TRIG pin
#define TRIG_OUTPUT     3
// update interval, make sure to keep it above 20ms
#define ULTRASONIC_TIMER_US       500000 

// the time the pulse was sent
volatile unsigned long ultrasonic_echo_start = 0;
// the distance once it's been measured
volatile unsigned long ultrasonic_distance = 0;

void ultrasonicPulse(){
    digitalWrite(TRIG_OUTPUT, HIGH);
    delayMicroseconds(10);
    digitalWrite(TRIG_OUTPUT, LOW);
}

void ultrasonicEcho(){
    // don't do anything if no pulse has been sent
    int echoVal = digitalRead(ECHO_INPUT);

    if(echoVal == HIGH){  // RISING
      ultrasonic_echo_start = micros(); // 프로그램이 시작하고 나서 
    }
    else{  // FALLING
        // calculate the distance by measuring how long it took to return the sound
        // The speed of sound is 343 m/s and we need half the time it took (since
        // the sound has to travel towards the object _AND_ back). So a single echo does
        // 1/(343/2) = 0.005831 seconds per meter
        ultrasonic_distance = (micros() - ultrasonic_echo_start) / 58;

        //ultrasonic_echo_start = 0;
    }
}

void setup(){
    Serial.begin(115200);
  
    // set the echo pin to receive interrupts, on an arduino uno only pin 2 and 3 can link to interrupts
    pinMode(ECHO_INPUT, INPUT);
    pinMode(TRIG_OUTPUT, OUTPUT);
  
    Timer1.initialize(ULTRASONIC_TIMER_US);
    Timer1.attachInterrupt(ultrasonicPulse);
    attachInterrupt(digitalPinToInterrupt(ECHO_INPUT), ultrasonicEcho, CHANGE);
}

void loop() {
  Serial.print("Distance: ");
  Serial.println(ultrasonic_distance);
  delay(1000);
}
