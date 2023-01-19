#include <EasyUltrasonic.h>
#include <cmath>



#define PWM_A 3
#define DIR_A 12
#define BRAKE_A 9

#define PWM_B 11
#define DIR_B 13
#define BRAKE_B 8

int outs_length = 6;
int outs[] = {PWM_A, PWM_B, DIR_A, DIR_B, BRAKE_A, BRAKE_B};

void move_(int speed_A, int speed_B){
  bool dir_a = speed_A > 0 ? 1 : 0;
  bool dir_b = speed_B > 0 ? 1 : 0;

  digitalWrite(DIR_A, dir_a);
  analogWrite(PWM_A, abs(speed_A));

  digitalWrite(DIR_B, dir_b);
  analogWrite(PWM_B, abs(speed_B));
  
}

// пдавнонго разгона + храним в глобальных переменных текущие скорости моторов

int last_speed_A;

for (int i = last_speed_A; i != speed_A;){
  delay(10);
}

EasyUltrasonic dist_sensor;

void setup() {

  digitalWrite(BRAKE_A, 0);
  digitalWrite(BRAKE_B, 0);

  for (int i = 0 ; i < outs_length; i++)
    pinMode(outs[i], OUTPUT);

  dist_sensor.attach(TRIG, ECHOE);

  dist = dist_sensor.getDistanceCM();

}

// Пишем пропорциональный регулятор;

int* P_reg(int finish_distance){
  dist = dist_sensor.getDistanceCM();

  error = dist - finish_distance;
  // if dist > finish_distance, then error > 0, we should move forward;
  // if dist < finish_distance, then error < 0, we should move back;

  move_(error*Kp, error*Kp);
  
}


void loop() {
  
  
  
}
