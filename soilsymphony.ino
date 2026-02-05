#include <Servo.h>

// Pin definitions
const int SERVO_PIN = 9;
const int SOIL_SENSOR_PIN = A0;
const int BUTTON_PIN = 2;
const int BAUD_RATE = 115200;

// Thresholds
const int DRY_THRESHOLD = 600;
const int WET_THRESHOLD = 400;
const int READ_INTERVAL = 5000; // 5 seconds

// Servo object
Servo pumpServo;

// State variables
bool pumpRunning = false;
bool lastButtonState = LOW;
unsigned long lastReadTime = 0;

void setup() {
  Serial.begin(BAUD_RATE);
  pumpServo.attach(SERVO_PIN);
  pumpServo.write(0); // Start at 0 degrees
  
  pinMode(BUTTON_PIN, INPUT);
  pinMode(SOIL_SENSOR_PIN, INPUT);
  
  Serial.println(">>> SoilSymphony Arduino initialized");
  Serial.println(">>> Servo on D9, Soil Sensor on A0, Button on D2");
}

void loop() {
  unsigned long currentTime = millis();

  // -------- PHYSICAL BUTTON CHECK --------
  int buttonState = digitalRead(BUTTON_PIN);
  if (buttonState == HIGH && lastButtonState == LOW && !pumpRunning) {
    Serial.println(">>> BUTTON PRESSED <<<");
    delay(50); // Debounce
    runPumpCycle();
  }
  lastButtonState = buttonState;

  // -------- SOIL MOISTURE READING --------
  if (currentTime - lastReadTime >= READ_INTERVAL && !pumpRunning) {
    lastReadTime = currentTime;
    int soilValue = analogRead(SOIL_SENSOR_PIN);
    Serial.print("Soil: ");
    Serial.print(soilValue);
    Serial.print(" | ");
    if (soilValue < WET_THRESHOLD) {
      Serial.println("STATE:WET");
    } else if (soilValue > DRY_THRESHOLD) {
      Serial.println("STATE:DRY");
    } else {
      Serial.println("STATE:NORMAL");
    }
  }

  // -------- SERIAL COMMANDS --------
  if (Serial.available()) {
    String cmd = Serial.readStringUntil('\n');
    cmd.trim();
    if (cmd.length() > 0) {
      Serial.print(">>> Received: '");
      Serial.print(cmd);
      Serial.println("'");
      
      // Handle MOVE commands from web app
      if (cmd.startsWith("MOVE:")) {
        if (!pumpRunning) {
          String angleStr = cmd.substring(5);
          int angle = angleStr.toInt();
          moveServo(angle);
        } else {
          Serial.println(">>> Pump already running, ignoring MOVE");
        }
      }
      // Handle TRIGGER command
      else if (cmd == "TRIGGER" && !pumpRunning) {
        runPumpCycle();
      } else if (cmd == "TRIGGER" && pumpRunning) {
        Serial.println(">>> Pump already running, ignoring");
      }
      // Handle STATUS command
      else if (cmd == "STATUS") {
        printStatus();
      } else {
        Serial.println(">>> Unknown command");
      }
    }
  }
}

void moveServo(int angle) {
  // Clamp angle between -180 and 180 for relative movement
  int targetAngle = 0 + angle; // Add to current 0 position
  targetAngle = constrain(targetAngle, 0, 180);
  
  Serial.print(">>> Moving servo to ");
  Serial.print(targetAngle);
  Serial.println("°");
  
  pumpServo.write(targetAngle);
  delay(100);
}

void runPumpCycle() {
  pumpRunning = true;
  Serial.println("TRIGGERED");
  
  // Pump cycle: move forward, then back, then home
  moveServo(23);     // Move to 23 degrees
  delay(3500);       // Hold for 3.5 seconds
  
  moveServo(180);    // Move opposite direction (simulating -157 by going to 180)
  delay(1000);       // Hold briefly
  
  moveServo(0);      // Return to start
  delay(500);
  
  Serial.println("DONE");
  pumpRunning = false;
}

void printStatus() {
  int soilValue = analogRead(SOIL_SENSOR_PIN);
  Serial.print("Status: Soil=");
  Serial.print(soilValue);
  Serial.print(", Servo=0°, PumpRunning=");
  Serial.println(pumpRunning ? "yes" : "no");
}
