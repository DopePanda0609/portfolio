#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>

// Create an instance of the PCA9685 servo driver
Adafruit_PWMServoDriver pwm;

// Servo parameters
const int servoMin = 150;   // Minimum pulse length (in microseconds)
const int servoMax = 600;   // Maximum pulse length (in microseconds)

// Potentiometer pins connected to Arduino analog inputs
const int potPin1 = A0;
const int potPin2 = A1;


// Servo pins connected to the PCA9685 channels
const int servoPin1 = 0;
const int servoPin2 = 1;

void setup() {
  // Initialize the servo driver
  pwm.begin();
  pwm.setPWMFreq(60);  // Set the PWM frequency (default is 50Hz)
}

void loop() {
  // Read the values from the potentiometers
  int joint1 = analogRead(potPin1);
  int joint2 = analogRead(potPin2);
  // Map the potentiometer values to servo angles
  int servoAngle1 = map(joint1, 945, 350, 180, 30);
  int servoAngle2 = map(joint2, 0, 755, 0, 150);
  // Set the positions of the servos
  setServoPosition(servoPin1, servoAngle1);
  setServoPosition(servoPin2, servoAngle2);
  delay(10);
}

void setServoPosition(int servoPin, int degrees) {
  // Map the desired angle to servo pulse width
  int pulseWidth = map(degrees, 0, 180, servoMin, servoMax);

  // Set the servo position using the PCA9685 servo driver
  pwm.setPWM(servoPin, 0, pulseWidth);
}
