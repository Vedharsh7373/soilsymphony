# SoilSymphony - Servo Motor Troubleshooting Guide

## PROBLEM: Servo Motor Not Spinning

If your servo motor is not spinning when you click "Water Now" button, follow this guide:

---

## STEP 1: Physical Wire Check

### Required Connections:
```
Servo Motor Connector:
  Orange/Yellow Wire → Arduino Pin D9
  Red Wire → 5V Power
  Brown/Black Wire → GND (Ground)

SOIL SENSOR:
  VCC → 5V
  GND → GND  
  Signal → A0

PUSH BUTTON (optional):
  Pin 1 → D2
  Pin 2 → GND
```

**CRITICAL:** All ground wires MUST be connected together (common GND).

---

## STEP 2: Test 1 - Simple Servo Spin

Upload this SIMPLE test code FIRST to verify servo works:

```cpp
#include <Servo.h>

Servo testServo;

void setup() {
  Serial.begin(115200);
  testServo.attach(9);
  Serial.println("Servo attached to D9");
  testServo.write(0);
  delay(1000);
}

void loop() {
  Serial.println("Moving to 90 degrees...");
  testServo.write(90);
  delay(2000);
  
  Serial.println("Moving to 180 degrees...");
  testServo.write(180);
  delay(2000);
  
  Serial.println("Moving to 0 degrees...");
  testServo.write(0);
  delay(2000);
}
```

**Instructions:**
1. Copy the above code
2. Open Arduino IDE
3. Paste into a NEW sketch
4. Select Board: Arduino Uno (or your board)
5. Select Port: COM3 (or whichever port your Arduino uses)
6. Click Upload
7. Open Serial Monitor (Tools → Serial Monitor)
8. Set baud to 115200
9. Watch the servo move - it should spin smoothly 0→90→180→0

**If servo spins:** Problem is fixed! Go to Step 4.
**If servo doesn't spin:** Go to Step 3.

---

## STEP 3: Servo Not Spinning? Diagnose Here

### Check 1: Power
- Does your servo make a humming sound? → Likely not getting enough current
- Buy a 5-6V external power supply
- Connect Servo Vcc to 5V power (NOT Arduino 5V pin)
- Connect Servo GND to Arduino GND (create common ground)

### Check 2: Signal Wire
- Make SURE orange/yellow wire is connected to D9
- Try a different Arduino pin (D3, D5, D6, D9, D10, D11)
- Modify the test code line 6: `testServo.attach(5);` (change 9 to your pin)

### Check 3: Servo is Dead
- Try a different servo motor
- Test servo with a servo tester (if available)

### Check 4: Arduino Board Issue
- Try uploading blink example to verify Arduino works
- Try analog write: `analogWrite(9, 180);` to test pin

---

## STEP 4: Servo Works! Now Use Full Code

Once simple test works:
1. Upload `soilsymphony.ino` to your Arduino
2. Open Serial Monitor at 115200 baud
3. You should see ">>> SoilSymphony Arduino initialized"
4. Open the web app: soilsymphony.vercel.app
5. Click "Connect to Arduino"
6. Click "💧 Water Now" button
7. Watch Serial Monitor for movement commands
8. Watch servo spin!

---

## STEP 5: Quick Debug Checklist

- [ ] Servo makes humming sound (has power)
- [ ] Orange wire on D9
- [ ] All GND connected together
- [ ] Arduino IDE shows "Upload successful"
- [ ] Serial Monitor shows initialization message
- [ ] Web app connects and shows "Serial: connected"
- [ ] No error messages in Serial Monitor

---

## COMMON ISSUES

### "Upload failed"
- Select correct Board type (Arduino Uno, Nano, Mega, etc.)
- Select correct COM port
- Try USB cable on different computer

### "Serial Monitor shows nothing"
- Check baud rate is 115200
- Try pressing Arduino reset button
- Check USB cable is connected

### Servo twitches but doesn't move
- Power issue - servo needs more current
- Use external 5V power supply, not Arduino power

### Web app says "Serial: disconnected"
- Click "Connect to Arduino" button again
- Make sure serial code is uploaded
- Check COM port in Arduino IDE matches browser

---

## Still Not Working?

Tell me:
1. Does the simple test code make servo move? (Yes/No)
2. Do you hear the servo humming? (Yes/No)
3. What Arduino board are you using? (Uno/Nano/Mega/etc)
4. What does Serial Monitor show? (paste text)
5. What error messages appear? (if any)
