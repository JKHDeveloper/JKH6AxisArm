#include <ESP32Servo.h>

Servo ServoAxis6, ServoAxis5, ServoAxis4;  // Create a servo object

int pos = 0;    // Variable to store the servo position

const int MAX_VALUES = 10; // Maximum number of values in the string

// Defining global variables
double x, y, z, r, p;
int rb, lb, a, b, c, d; 
int commaLocations[MAX_VALUES]; 

void setup() {

  // Setting up comms
  Serial.begin(115200); // Set baud rate to 9600
  Serial.setTimeout(10);

  // Setting default values


  // Setting up servo motors
  ESP32PWM::allocateTimer(0);
  ESP32PWM::allocateTimer(1);
  ESP32PWM::allocateTimer(2);
  
  ServoAxis6.setPeriodHertz(50);    // standard 50 hz servo
  ServoAxis6.attach(5, 600, 2400); // attaches the servo on pin 18 to the servo object

  ServoAxis5.setPeriodHertz(50);    // standard 50 hz servo
  ServoAxis5.attach(18, 600, 2400); // attaches the servo on pin 18 to the servo object

  ServoAxis4.setPeriodHertz(50);    // standard 50 hz servo
  ServoAxis4.attach(19, 600, 2400); // attaches the servo on pin 18 to the servo object
}

void loop() {

    if (Serial.available()) {
      // Read the incoming byte
      String incoming = Serial.readStringUntil('\n');
      Serial.print(incoming + '\n');

      // Finding the commas in the input
      commaLocations[0] = incoming.indexOf(",");
      commaLocations[1] = incoming.indexOf(",", commaLocations[0]+1);
      commaLocations[2] = incoming.indexOf(",", commaLocations[1]+1);
      commaLocations[3] = incoming.indexOf(",", commaLocations[2]+1);
      commaLocations[4] = incoming.indexOf(",", commaLocations[3]+1);
      commaLocations[5] = incoming.indexOf(",", commaLocations[4]+1);
      commaLocations[6] = incoming.indexOf(",", commaLocations[5]+1);
      commaLocations[7] = incoming.indexOf(",", commaLocations[6]+1);
      commaLocations[8] = incoming.indexOf(",", commaLocations[7]+1);
      commaLocations[9] = incoming.indexOf(",", commaLocations[8]+1);

      // Checking if any commas missed
      bool failedToRead = false;
      for (int i = 0; i<10; i++){
        // Serial.println(commaLocations[i]);

        if(commaLocations[i] == -1)
          failedToRead = true;
      }

      // If it's read sucessfully then split into substrings
      if (!failedToRead) {
        // Serial.println("Sucessfully Read");
        double newX = incoming.substring(0,commaLocations[0]).toDouble();
        double newY = incoming.substring(commaLocations[0]+1,commaLocations[1]).toDouble();
        double newZ = incoming.substring(commaLocations[1]+1,commaLocations[2]).toDouble();
        double newR = incoming.substring(commaLocations[2]+1,commaLocations[3]).toDouble();
        double newP = incoming.substring(commaLocations[3]+1,commaLocations[4]).toDouble();
        int newRB = incoming.substring(commaLocations[4]+1,commaLocations[5]).toInt();
        int newLB = incoming.substring(commaLocations[5]+1,commaLocations[6]).toInt();
        int newA = incoming.substring(commaLocations[6]+1,commaLocations[7]).toInt();
        int newB = incoming.substring(commaLocations[7]+1,commaLocations[8]).toInt();
        int newC = incoming.substring(commaLocations[8]+1,commaLocations[9]).toInt();
        int newD = incoming.substring(commaLocations[9]+1,incoming.length()).toInt();


        // Incrementing values
        x += newX/100;
        y += newY/100;
        z += newZ/100;

        // Scaling Values
        int servoX = (x+1)*90;
        int servoY = (y+1)*90;
        int servoZ = (z+1)*90;

        //Serial.println(servoX);
        ServoAxis6.write(servoX);
        ServoAxis5.write(servoY);
        ServoAxis4.write(servoZ);


      }
    }
}

