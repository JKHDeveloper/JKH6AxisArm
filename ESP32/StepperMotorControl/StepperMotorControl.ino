// Define the pin numbers
#define STEP_PIN 25
#define DIR_PIN 14

void setup() {
  // Set the STEP and DIR pins as outputs
  pinMode(STEP_PIN, OUTPUT);
  pinMode(DIR_PIN, OUTPUT);

  // Set the initial direction (clockwise)
  digitalWrite(DIR_PIN, HIGH);
}

void loop() {
  // Sweep the stepper motor back and forth

  // Step forward (clockwise)
  digitalWrite(DIR_PIN, HIGH);
  for (int i = 0; i < 100; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delay(500);  // Adjust this delay for speed control
    digitalWrite(STEP_PIN, LOW);
    delay(500);  // Adjust this delay for speed control
  }

  delay(1000);  // Pause for 1 second

  // Step backward (counter-clockwise)
  digitalWrite(DIR_PIN, LOW);
  for (int i = 0; i < 100; i++) {
    digitalWrite(STEP_PIN, HIGH);
    delay(500);  // Adjust this delay for speed control
    digitalWrite(STEP_PIN, LOW);
    delay(500);  // Adjust this delay for speed control
  }

  delay(1000);  // Pause for 1 second
}
