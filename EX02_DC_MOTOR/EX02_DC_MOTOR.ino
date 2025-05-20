#define STOP 0
#define CW   1
#define CCW  2

const int DC_E = 3;
const int DC_P = 5;
const int DC_N = 4;

void setup() {
  // put your setup code here, to run once:
  pinMode(DC_E, OUTPUT);
  pinMode(DC_P, OUTPUT);
  pinMode(DC_N, OUTPUT);

  DC_MOTOR_cntl(CW, 1000);
  DC_MOTOR_cntl(STOP, 1000);
  DC_MOTOR_cntl(CCW, 1000);
  DC_MOTOR_cntl(STOP, 1000);
}

void loop() {
  // put your main code here, to run repeatedly:

}

void DC_MOTOR_cntl(int mode, int time)
{
    switch(mode){
      case STOP:
        digitalWrite(DC_E, LOW);
        digitalWrite(DC_P, LOW);
        digitalWrite(DC_N, LOW);
        break;

      case CW:
        digitalWrite(DC_E, HIGH);
        digitalWrite(DC_P, HIGH);
        digitalWrite(DC_N, LOW);
        break;

      case CCW:
        digitalWrite(DC_E, HIGH);
        digitalWrite(DC_P, LOW);
        digitalWrite(DC_N, HIGH);
        break;

      default:
        digitalWrite(DC_E, LOW);
        digitalWrite(DC_P, LOW);
        digitalWrite(DC_N, LOW);
        break;
    }
    delay(time);
}