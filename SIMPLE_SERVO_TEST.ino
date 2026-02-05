// SIMPLE SERVO TEST - Use this to diagnose if your servo works
// Upload this FIRST before using the full soilsymphony.ino

#include <Servo.h>

Servo testServo;

void setup() {
  Serial.begin(115200);
  delay(500);
  
  testServo.attach(9); // Servo signal wire on D9
  testServo.write(0);  // Start at 0 degrees
  
  Serial.println("\n\n========================================");
  Serial.println("SIMPLE SERVO TEST - soilsymphony");
  Serial.println("========================================");
  Serial.println("Servo attached to Pin D9");
  Serial.println("Expected: Servo should move smoothly");
  Serial.println("If nothing happens, check:");
  Serial.println("  1. Orange/Yellow wire on D9");
  Serial.println("  2. Red wire on 5V power");
  Serial.println("  3. Brown/Black wire on GND");
  Serial.println("  4. All GND wires connected together");
  Serial.println("========================================\n");
}

void loop() {
  // Move to 90 degrees
  Serial.println("Moving to 90 degrees...");
  testServo.write(90);
  delay(2000);
  
  // Move to 180 degrees
  Serial.println("Moving to 180 degrees...");
  testServo.write(180);
  delay(2000);
  
  // Return to 0 degrees
  Serial.println("Returning to 0 degrees...");
  testServo.write(0);
  delay(2000);
  
  Serial.println("");
}
