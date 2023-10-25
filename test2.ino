#include <Stepper.h>
#define stepsPerRevolution 200

const int stepPins1[] = {8, 9, 10, 11};
const int stepPins2[] = {4, 5, 6, 7};

Stepper myStepper1(stepsPerRevolution, stepPins1[0], stepPins1[1], stepPins1[2], stepPins1[3]);
Stepper myStepper2(stepsPerRevolution, stepPins2[0], stepPins2[1], stepPins2[2], stepPins2[3]);

void setup() {
  myStepper1.setSpeed(100);
  myStepper2.setSpeed(100);
  Serial.begin(9600);
}

void loop() {
  Serial.println("Quay theo chiều kim đồng hồ cho động cơ 1");
  myStepper1.step(250); // Số bước mỗi lần quay
  delay(500);

  
  Serial.println("Quay ngược chiều kim đồng hồ cho động cơ 2");
  myStepper2.step(-250); 
  delay(500);
}
