const int ROW[4] = {13, 12, 11, 10};  //OUTPUT
const int COL[4] = {9, 8, 7, 6};   //INPUT
int colVal[4] = {LOW};

void setup() {
  // put your setup code here, to run once:
  for (int i = 0; i < 4; i++) {
    pinMode(ROW[i], OUTPUT);
    digitalWrite(ROW[i], LOW);

    pinMode(COL[i], INPUT); 
  }

  Serial.begin(115200);

}

void loop() {
  // put your main code here, to run repeatedly:
  for(int i = 0; i < 4; i++) {
    digitalWrite(ROW[i], HIGH);
    //col read
    for(int j = 0; j < 4; j++) {
      colVal[j] = digitalRead(COL[j]);
    }

    digitalWrite(ROW[i], LOW);

    for(int j = 0; j < 4; j++) {
      if(colVal[j] == HIGH) {
        // Serial.print("Row: ");
        // Serial.print(i);
        // Serial.print(" , Col: ");
        // Serial.print(j);
        // Serial.print(" -> ");
        Serial.println(i * 4 + j, HEX);

        delay(200);
      }
    }
  }

}
