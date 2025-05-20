void setup() {
  // put your setup code here, to run once:
  //printf("hello, world..!!");
  Serial.begin(115200);
  Serial.println("Hello World..!!");
  Serial.println(78);
  Serial.println(1.23456);
  Serial.println('N');

  Serial.print("Hello World..!!");
  Serial.print(78);
  Serial.print(1.23456);
  Serial.print('N');

  Serial.println();

  Serial.println(78, DEC);
  Serial.println(78, HEX);
  Serial.println(78, BIN);

  Serial.println(1.23456, 0);
  Serial.println(1.23456, 4);
  Serial.println(1.23456, 2);
}
                                                                                                           
void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println("Hello World..!!");
}
