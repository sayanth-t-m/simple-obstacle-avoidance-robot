//super_ultra_1

#include <NewPing.h>

#define motor1Pin1 7
#define motor1Pin2 8
#define motor2Pin1 9
#define motor2Pin2 10

#define trigPin 3
#define echoPin 2

#define MAX_DISTANCE 200
#define OBSTACLE_DISTANCE 40
#define TURN_TIME_180_DEG 1500  // Adjusted turn time for 180 degrees
#define TURN_TIME_45_DEG 375    // Adjusted turn time for 45 degrees
#define TURN_TIME_25_DEG 200    // Adjusted turn time for 25 degrees
#define MOVE_TIME 100

NewPing sonar(trigPin, echoPin, MAX_DISTANCE);

unsigned int turnSequence[] = {TURN_TIME_180_DEG, TURN_TIME_45_DEG, TURN_TIME_25_DEG, TURN_TIME_180_DEG, TURN_TIME_45_DEG, TURN_TIME_25_DEG};
int sequenceIndex = 0;

void setup() {
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(motor2Pin1, OUTPUT);
  pinMode(motor2Pin2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  uint8_t distance = getDistance();
  Serial.print("Distance: ");
  Serial.println(distance);

  if (distance < OBSTACLE_DISTANCE) {
    avoidObstacle();
  } else {
    move(MOVE_TIME, HIGH, LOW, HIGH, LOW);
  }

  delay(100);
}

uint8_t getDistance() {
  uint8_t distance = sonar.ping_cm();
  return (distance == 0) ? MAX_DISTANCE : distance;
}

void avoidObstacle() {
  stopRobot();
  delay(500);

  for (int i = 0; i < 6; i++) {
    if (turnAndCheck(turnSequence[sequenceIndex])) {
      break;
    }
    sequenceIndex = (sequenceIndex + 1) % 6;  // Move to the next turn in the sequence
  }
}

bool turnAndCheck(unsigned long turnTime) {
  // Choose the turn configuration here if needed
  move(turnTime, LOW, HIGH, HIGH, LOW); // Example turn configuration
  stopRobot();
  delay(100);

  return (getDistance() >= OBSTACLE_DISTANCE);
}

void move(unsigned long duration, uint8_t m1Pin1State, uint8_t m1Pin2State, uint8_t m2Pin1State, uint8_t m2Pin2State) {
  digitalWrite(motor1Pin1, m1Pin1State);
  digitalWrite(motor1Pin2, m1Pin2State);
  digitalWrite(motor2Pin1, m2Pin1State);
  digitalWrite(motor2Pin2, m2Pin2State);
  delay(duration);
}

void stopRobot() {
  move(0, LOW, LOW, LOW, LOW);
}