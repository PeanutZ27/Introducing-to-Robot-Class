#include"motor.cpp"
// Motor R
int enA = 10;
int in1 = 9;
int in2 = 8;
// Motor L
int enB = 11;
int in3 = 13;
int in4 = 12;

int L = digitalRead(5);
int R = digitalRead(4);
int M = digitalRead(6);

int turn_ms = 0;

Motor L_motor(in4, in3, enB);
Motor R_motor(in1, in2, enA);
Dual_motor Dual(L_motor, R_motor);


void setup() {
  Serial.begin(115200);
  Serial.println("Hello world");
  pinMode(4, INPUT);
  pinMode(5, INPUT);
  delay(500);

}

void loop() {



}
void trackLine(int sl, int sr , int turn_ms) {
  readSensor();
  if (L == 1 && R == 1) {
    m(sl, sr, turn_ms);
  }
  else if (L == 0 && R == 1) {
    sl(sl, sr);
    delay(turn_ms);
  }
  else if (L == 1 && R == 0) {
    sr(sl, sr);
    delay(turn_ms);
  }
  else {
    stop(false);
  }
}

void trackLine_R (int sl, int sr , int turn_ms , int line)
int count = 0;
while (count > line) {

  trackLine1(sl, sr);
  if (M == 0 && R == 0) {
    while (M == 0 && R == 0) {
      m(sl, sr, turn_ms);
      readSensor();
    }
    count++;
  }
  stop(false);
}

void m(int l, int r, int ms) {
  Dual.m(l, r);
  delay(ms);
}
void readSensor() {
  L = digitalRead(5);
  R = digitalRead(4);
  M = digitalRead(6);
}
