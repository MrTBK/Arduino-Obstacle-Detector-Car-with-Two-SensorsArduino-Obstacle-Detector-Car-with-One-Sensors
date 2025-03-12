int trig = 4;  // Trigger pin for the sensor
int echo = 7;  // Echo pin for the sensor
int IN1 = 5;    // Motor driver pin for front left motor
int IN2 = 6;    // Motor driver pin for front left motor
int IN3 = 9;    // Motor driver pin for back left motor
int IN4 = 10;   // Motor driver pin for back left motor
long x;         // Variable to store the pulse duration
int distance;   // Variable to store the distance reading from the sensor

void setup() {
  Serial.begin(9600);      // Initialize serial communication
  pinMode(trig, OUTPUT);   // Set the trig pin as an output
  pinMode(echo, INPUT);    // Set the echo pin as an input
  pinMode(IN1, OUTPUT);    // Set the motor control pins as outputs
  pinMode(IN2, OUTPUT);
  pinMode(IN3, OUTPUT);
  pinMode(IN4, OUTPUT);
}

void loop() {
  delay(100);             // Delay to avoid too many readings

  // Send a pulse to the sensor
  digitalWrite(trig, LOW);
  delayMicroseconds(4);
  digitalWrite(trig, HIGH);
  delayMicroseconds(10);
  digitalWrite(trig, LOW);

  // Measure the pulse duration
  x = pulseIn(echo, HIGH);
  distance = x / 58;  // Convert the pulse duration to distance

  // If the distance is greater than 10 cm, move forward
  if (distance > 10) {
    if (distance > 20) {
      avance();  // Move forward
    } else {
      arret(100);  // Stop briefly
      if (distance < 15) {
        recul();  // Move backward
        delay(300);
        arret(100);  // Stop briefly
      } else {
        droite();  // Turn right
        delay(400);
        arret(100);  // Stop briefly
      }
    }
  } else {
    recul();  // Move backward if an obstacle is too close
    delay(400);
    arret(100);  // Stop briefly
  }
}

// Function to stop the motors
void arret(int temps) {
  arreter();    // Stop the motors
  delay(temps); // Wait for the specified time
}

// Function to move forward
void avance() {
  analogWrite(IN1, 150);
  analogWrite(IN2, 0);
  analogWrite(IN3, 150);
  analogWrite(IN4, 0);
}

// Function to move backward
void recul() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 150);
  analogWrite(IN3, 0);
  analogWrite(IN4, 150);
}

// Function to turn right
void droite() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 150);
  analogWrite(IN4, 0);
}

// Function to stop all motors
void arreter() {
  analogWrite(IN1, 0);
  analogWrite(IN2, 0);
  analogWrite(IN3, 0);
  analogWrite(IN4, 0);
}
