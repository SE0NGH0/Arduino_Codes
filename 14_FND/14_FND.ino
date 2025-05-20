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

void display_init(int *pin){
  for(int i=0; i<7; i++){
    pinMode(*(pin+i), OUTPUT);
  }
}
void display_set(int *pin){
  for(int i=0; i<7; i++){
    digitalWrite(*(pin+i), HIGH);
  }
}
void display_clear(int *pin){
  for(int i=0; i<7; i++){
    digitalWrite(*(pin+i), LOW);
  }
}

void display_number(int n){
  for(int i=0; i<7; i++)  {
    digitalWrite(fnd_data[i], num_dec[n][i]);
  }
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  display_init(fnd_data);
  display_clear(fnd_data);
}

void loop() {
  // put your main code here, to run repeatedly:
  if(Serial.available()){
    char userInput = Serial.read();
    if( (userInput >= '0') && (userInput <= '9') ){
      int num = userInput - '0';
      display_number(num);
    }
  }
}
