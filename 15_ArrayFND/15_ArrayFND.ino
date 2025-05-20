//#include <TimerOne.h>
#define delayVal  0

unsigned long t1_prev = 0;
const unsigned long t1_delay = 1;

unsigned long t2_prev = 0;
const unsigned long t2_delay = 300;
int led_flag = 0;

const int LED = 13;
const int fnd_digit[6] = {A0, A1, A2, A3, A4, A5};
const int fnd_data[7] = { 2, 3, 4, 5, 6, 7, 8};
                    // a, b, c, d, e, f, g
const int num_0[7] = { 1, 1, 1, 1, 1, 1, 0};
const int num_1[7] = { 0, 1, 1, 0, 0, 0, 0};
const int num_2[7] = { 1, 1, 0, 1, 1, 0, 1};
const int num_3[7] = { 1, 1, 1, 1, 0, 0, 1};
const int num_4[7] = { 0, 1, 1, 0, 0, 1, 1};
const int num_5[7] = { 1, 0, 1, 1, 0, 1, 1};
const int num_6[7] = { 1, 0, 1, 1, 1, 1, 1};
const int num_7[7] = { 1, 1, 1, 0, 0, 0, 0};
const int num_8[7] = { 1, 1, 1, 1, 1, 1, 1};
const int num_9[7] = { 1, 1, 1, 1, 0, 1, 1};

const int *num_dec[10] = {num_0,num_1,num_2,num_3,num_4,num_5,num_6,num_7,num_8,num_9};

//unsigned long num = 0;

void display_init(void){
  for(int i=0; i<6; i++){
    pinMode(fnd_digit[i], OUTPUT);
    digitalWrite(fnd_digit[i], LOW);
  }
  for(int i=0; i<7; i++){
    pinMode(fnd_data[i], OUTPUT);
    digitalWrite(fnd_data[i], LOW);
  }
}
void display_set(void){
  for(int i=0; i<7; i++){
    digitalWrite(fnd_data[i], HIGH);
  }
}
void display_clear(void){
  for(int i=0; i<7; i++){
    digitalWrite(fnd_data[i], LOW);
  }
}

void display_number(int n, int d){
  display_clear();

  // 표시할 자리 설정
  for(int i=0; i<6; i++){
    digitalWrite(fnd_digit[i], HIGH);
  }
  digitalWrite(fnd_digit[d-1], LOW);

  // 표시할 데이터 설정
  for(int i=0; i<7; i++)  {
    digitalWrite(fnd_data[i], num_dec[n][i]);
  }
}

void display_numbers(unsigned long numbers){
  unsigned long num_100000 = numbers / 100000;
  unsigned long num_10000 = (numbers % 100000) / 10000;
  unsigned long num_1000 = (numbers % 10000) / 1000;
  unsigned long num_100 = (numbers % 1000) / 100;
  unsigned long num_10 = (numbers % 100) / 10;
  unsigned long num_1 = numbers % 10;

  display_number(num_100000, 1);
  display_number(num_10000, 2);
  display_number(num_1000, 3);
  display_number(num_100, 4);
  display_number(num_10, 5);
  display_number(num_1, 6);
}

// ISR 함수
// void timer1Isr(void) {
//   num++;
// }

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  display_init();
  display_clear();

  pinMode(LED, OUTPUT);

  //Timer1.initialize(10000);
  //Timer1.attachInterrupt(timer1Isr);
}

void loop() {
  //put your main code here, to run repeatedly:
  static unsigned int num = 0;

  if(Serial.available()) {
    char userInput = Serial.read();
    switch(userInput) {
      case '0': num = 0; break;
      case '1': num = 1; break;
      case '2': num = 2; break;
      case '3': num = 3; break;
      default: break;
    }
  }

  unsigned long t1_now = millis();
  if(t1_now - t1_prev >= t1_delay) {
    t1_prev = t1_now;
    
    display_numbers(num);
  }

  unsigned long t2_now = millis();
  if(t2_now - t2_prev >= t2_delay) {
    t2_prev = t2_now;

    if(led_flag == 0) {
      digitalWrite(LED, HIGH);
      led_flag = 1;
    } 
    else {
      digitalWrite(LED, LOW);
      led_flag = 0;
    }
  }
}
