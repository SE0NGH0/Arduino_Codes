const uint8_t SW_0 = 2;
const uint8_t LED_0 = 13;
const uint8_t SW_1 = 3;
const uint8_t LED_1 = 12;

int led_flag_0 = 0;  // 0 : OFF, 1 : ON
int led_flag_1 = 0;
int pre_sw_0 = 0;
int cur_sw_0 = 0;
int pre_sw_1 = 0;
int cur_sw_1 = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);
}

void loop() {
  // put your main code here, to run repeatedly:

  cur_sw_0 = digitalRead(SW_0);  // 현재값 갱신
  cur_sw_1 = digitalRead(SW_1);

  if ((pre_sw_0 == LOW) && (cur_sw_0 == HIGH)) 
  {
    // 스위치가 눌렸을 때 led_flag_0의 값만 변경
    if (led_flag_0 == 0) 
    {
      led_flag_0 = 1;
    } 
    else 
    {
      led_flag_0 = 0;
    }
    delay(300);
  }

  if ((pre_sw_1 == LOW) && (cur_sw_1 == HIGH)) 
  {
    if (led_flag_1 == 0) 
    {
      led_flag_1 = 1;
    } 
    else 
    {
      led_flag_1 = 0;
    }
    delay(300);
  }

  // led_flag의 값에 따른 동작 구현
  if(led_flag_0 == 0)
  {
    digitalWrite(LED_0, LOW);
  }
  else
  {
    digitalWrite(LED_0, HIGH);
    delay(500);
    digitalWrite(LED_0, LOW);
    delay(500);
  }

  if(led_flag_1 == 0)
  {
    digitalWrite(LED_1, LOW);
  }
  else
  {
    digitalWrite(LED_1, HIGH);
    delay(300);
    digitalWrite(LED_1, LOW);
    delay(300);
  }

  pre_sw_0 = cur_sw_0;  // 이전값 갱신
  pre_sw_1 = cur_sw_1;
}
