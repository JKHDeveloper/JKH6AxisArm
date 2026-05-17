#include <Arduino.h>

void setup() {
    Serial.begin(115200); // Set baud rate to 9600
    Serial.setTimeout(10);
}

void loop() {
    if (Serial.available() > 0) {
        String receivedString = Serial.readStringUntil('\n'); // Read until newline character

        // Print the received UTF-16 encoded string
        Serial.println(receivedString);


        
    }
}
