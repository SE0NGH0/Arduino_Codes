#define V0 5.0
#define unit V0/1024.0
#define R1 1000.0

const int analogPin = A0;
const int LED_0 = 3;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);
  pinMode(LED_0, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  int analogValue = analogRead(analogPin);
  float V2 = analogValue * unit;
  float R2 = (V2 * R1) / (V0 - V2);
  Serial.print(analogValue);
  Serial.print(", ");
  Serial.print(V2);
  Serial.print("V, ");
  Serial.print(R2);
  Serial.println("Ω");

  int brightness = map(analogValue, 150, 1023, 0, 255);
  analogWrite(LED_0, brightness);

  delay(300);

}
