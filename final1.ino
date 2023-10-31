// Motor pin connections
int motor1A = 2; // Motor 1
int motor1B = 3;
int motor2A = 4; // Motor 2
int motor2B = 5;
int motor3A = 6; // Motor 3
int motor3B = 7;
int motor4A = 8; // Motor 4
int motor4B = 9;

// 4-channel IR sensor pins
int irSensor1 = A0;
int irSensor2 = A1;
int irSensor3 = A2;
int irSensor4 = A3;

// Ultrasonic sensor pins
int usSensor1Trigger = 10; // Ultrasonic sensor 1 trigger
int usSensor1Echo = 11;    // Ultrasonic sensor 1 echo

void setup() {
  // Initialize motor pins as outputs
  pinMode(motor1A, OUTPUT);
  pinMode(motor1B, OUTPUT);
  pinMode(motor2A, OUTPUT);
  pinMode(motor2B, OUTPUT);
  pinMode(motor3A, OUTPUT);
  pinMode(motor3B, OUTPUT);
  pinMode(motor4A, OUTPUT);
  pinMode(motor4B, OUTPUT);
  
  // Set 4-channel IR sensor pins as inputs
  pinMode(irSensor1, INPUT);
  pinMode(irSensor2, INPUT);
  pinMode(irSensor3, INPUT);
  pinMode(irSensor4, INPUT);
  
  // Set ultrasonic sensor trigger pin as output and echo pin as input
  pinMode(usSensor1Trigger, OUTPUT);
  pinMode(usSensor1Echo, INPUT);
  
  // Start serial communication for debugging
  Serial.begin(9600);
}

void loop() {
  int irValue1 = digitalRead(irSensor1);
  int irValue2 = digitalRead(irSensor2);
  int irValue3 = digitalRead(irSensor3);
  int irValue4 = digitalRead(irSensor4);
  
  long duration1;
  digitalWrite(usSensor1Trigger, LOW);
  delayMicroseconds(2);
  digitalWrite(usSensor1Trigger, HIGH);
  delayMicroseconds(10);
  digitalWrite(usSensor1Trigger, LOW);
  duration1 = pulseIn(usSensor1Echo, HIGH);

  // Maze-solving and wall-following logic
  if (irValue1 == LOW && irValue2 == LOW && irValue3 == HIGH && irValue4 == HIGH) {
    // No obstacles on both sides, move forward
    moveForward();
  } else if (irValue1 == HIGH && irValue2 == LOW && irValue3 == HIGH && irValue4 == LOW) {
    // Turn right
    stop();
    turnRight();
  } else if (irValue1 == LOW && irValue2 == HIGH && irValue3 == LOW && irValue4 == HIGH) {
    // Turn left
    stop();
    turnLeft();
  } else {
    // Obstacle detected in front, turn left
    stop();
    turnLeft();
  }

  // Obstacle avoidance
  if (duration1 < 15) {
    stop();
    reverse();
    delay(500);
    stop();
    turnLeft();
    delay(500);
  }

  // Print sensor data for debugging
  Serial.print("IR: ");
  Serial.print(irValue1);
  Serial.print(irValue2);
  Serial.print(irValue3);
  Serial.print(irValue4);
  Serial.print(" | US: ");
  Serial.println(duration1);
}

// Motor control functions
void moveForward() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, HIGH);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, HIGH);
  digitalWrite(motor4B, LOW);
}

void turnRight() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, HIGH);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, HIGH);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, LOW);
}

void turnLeft() {
  digitalWrite(motor1A, HIGH);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, HIGH);
  digitalWrite(motor4B, LOW);
}

void stop() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, LOW);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, LOW);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, LOW);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, LOW);
}

void reverse() {
  digitalWrite(motor1A, LOW);
  digitalWrite(motor1B, HIGH);
  digitalWrite(motor2A, LOW);
  digitalWrite(motor2B, HIGH);
  digitalWrite(motor3A, LOW);
  digitalWrite(motor3B, HIGH);
  digitalWrite(motor4A, LOW);
  digitalWrite(motor4B, HIGH);
}
