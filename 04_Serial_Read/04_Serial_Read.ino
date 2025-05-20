const int LED_0 = 13;
const int LED_1 = 12;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_0, OUTPUT);
  pinMode(LED_1, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char userInput[30] = {0, };
    Serial.readBytesUntil('\n', userInput, 30);

    if(strcmp("L0_ON", userInput) == 0){
      digitalWrite(LED_0, HIGH);
    }
    else if(strcmp("L0_OFF", userInput) == 0){
      digitalWrite(LED_0, LOW);
    }
    else if(strcmp("L1_ON", userInput) == 0){
      digitalWrite(LED_1, HIGH);
    }
    else if(strcmp("L1_OFF", userInput) == 0){
      digitalWrite(LED_1, LOW);
    }
  }

}
