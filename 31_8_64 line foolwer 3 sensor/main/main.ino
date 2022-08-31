#include"motor.cpp"
// Motor R
int enA = 10;
int in1 = 9;
int in2 = 8;
// Motor L 
int enB = 11;
int in3 = 13;
int in4 = 12;

int turn_ms = 0;

Motor L_motor(in4,in3,enB);
Motor R_motor(in1,in2,enA);
Dual_motor Dual(L_motor,R_motor);

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

void m(int l,int r){
    Dual.m(l,r);
}
