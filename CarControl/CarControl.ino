// Motor A connections
#define in1 18
#define in2 16

int speed = 200;  // Initial speed, ranging from 0 to 255

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  if (Serial.available() > 0) {
    char command = Serial.read();
    executeCommand(command);
  }
}

void executeCommand(char command) {
  switch (command) {
    case 'F':
      forward();
      break;
    case 'S':
      stop();
      break;
    case '+':
      increaseSpeed();
      break;
    case '-':
      decreaseSpeed();
      break;
    default:
      break;
  }
}

void forward() {
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
}

void stop() {
  analogWrite(in1, speed);
  digitalWrite(in2, LOW);
}

void increaseSpeed() {
  if (speed < 255) {
    speed += 10;  // Increase speed by 10
  }
}

void decreaseSpeed() {
  if (speed > 0) {
    speed -= 10;  // Decrease speed by 10
  }
}
