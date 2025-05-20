const uint8_t SW_0 = 2;
const uint8_t LED_0 = 13;
const uint8_t SW_1 = 3;
const uint8_t LED_1 = 12;

int led_flag_0 = 0;  // 0 : OFF, 1 : ON
int led_flag_1 = 0;

// 사용자 함수
void SW0_Pressed(void) {
    if (led_flag_0 == 0) 
    {
      led_flag_0 = 1;
    } 
    else 
    {
      led_flag_0 = 0;
    }
}

void SW1_Pressed(void) {
    if (led_flag_1 == 0) 
    {
      led_flag_1 = 1;
    } 
    else 
    {
      led_flag_1 = 0;
    }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(SW_0, INPUT);
  pinMode(SW_1, INPUT);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);
  digitalWrite(LED_0, LOW);
  digitalWrite(LED_1, LOW);

  attachInterrupt(digitalPinToInterrupt(SW_0), SW0_Pressed, RISING);
  attachInterrupt(digitalPinToInterrupt(SW_1), SW1_Pressed, RISING);
}

void loop() {
  // put your main code here, to run repeatedly:
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
}
