#include <ESP32Servo.h>

Servo myservo;  // Create a servo object
int pos = 0;    // Variable to store the servo position

const int MAX_VALUES = 12; // Maximum number of values in the string

int idx1, idx2, idx3; 

void setup() {
    Serial.begin(115200); // Set baud rate to 9600
    Serial.setTimeout(10);


    ESP32PWM::allocateTimer(0);
    myservo.setPeriodHertz(50);    // standard 50 hz servo
    myservo.attach(5, 1000, 2000); // attaches the servo on pin 18 to the servo object
}

void loop() {

    double values[MAX_VALUES];

    double x, y;

    if (Serial.available()) {
      // Read the incoming byte
      String incoming = Serial.readStringUntil('\n');
      Serial.print(incoming + '\n');

      // Finding the commas in the input
      idx1 = incoming.indexOf(",");
      idx2 = incoming.indexOf(",", idx1+1);
      idx3 = incoming.indexOf(",", idx2+1);

      if (idx1 != -1 && idx2 != -1 && idx3 != -1) {

        String xStr = incoming.substring(0,idx1);
        String yStr = incoming.substring(idx1+1,idx2);
        
        // Convert to doubles
        x = xStr.toInt();
        y = yStr.toInt();
      }

      Serial.println(x);
      Serial.println(y);
    }

    myservo.write(x);
    delay(500);
    myservo.write(y);
    delay(500);
}

