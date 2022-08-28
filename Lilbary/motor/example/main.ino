#include<motor.cpp>
// Motor A 
int enA = 9;
int in1 = 8;
int in2 = 7;
// Motor B 
int enB = 3;
int in3 = 5;
int in4 = 4;


Motor L_motor(in1,in2,enA);
Motor R_motor(in3,in4,enB);
Dual_motor Dual(L_motor,R_motor);


void setup(){
    Serial.begin(115200);
    Serial.println("Hello world");
    m(105,95);delay(1900);m(0,0);delay(500);
    m(90,0);delay(750);m(0,0);delay(500);
    m(105,95);delay(600);m(0,0);delay(500);
    m(90,0);delay(600);m(0,0);delay(500);
    m(105,95);delay(800);m(0,0);delay(500);
    m(90,0);delay(350);m(0,0);delay(500);
    m(105,95);delay(1350);m(0,0);delay(500);
}

void loop(){

}

void m(int l,int r){
    Dual.m(l,r);
}