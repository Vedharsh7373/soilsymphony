# SoilSymphony - Quick Start Guide

## 🚀 Get Your Servo Motor Spinning in 5 Minutes

### Step 1: Download the Code
Clone or download this repository to your computer.

### Step 2: Wire Your Arduino

**You need:**
- Arduino Uno (or compatible)
- Servo motor (SG90 or similar)
- Soil moisture sensor (optional)
- Push button (optional)
- USB cable

**Connections:**
```
Servo Motor:
  Orange/Yellow Wire → Arduino D9
  Red Wire → 5V
  Brown/Black Wire → GND

COMMON GROUND:
  All GND wires must connect together
```

### Step 3: Upload Code to Arduino

**IF YOU HAVE NEVER DONE THIS BEFORE:**
1. Download Arduino IDE from arduino.cc
2. Install the Servo library (comes with Arduino)
3. Open SIMPLE_SERVO_TEST.ino
4. Click Tools → Board → Arduino Uno
5. Click Tools → Port → COM3 (or whichever port shows up)
6. Click Upload button
7. Open Tools → Serial Monitor
8. Set baud to 115200
9. **Watch your servo spin!**

**If servo spins:** Perfect! Now upload soilsymphony.ino
**If servo doesn't spin:** Read TROUBLESHOOTING.md

### Step 4: Connect the Web App
1. Open browser to: soilsymphony.vercel.app
2. Click "Connect to Arduino"
3. Select your COM port
4. Click "💧 Water Now"
5. Watch servo spin from web app!

---

## 📁 Files Explained

| File | Purpose |
|------|----------|
| **SIMPLE_SERVO_TEST.ino** | Start HERE - tests if servo works |
| **soilsymphony.ino** | Full Arduino code with plant monitoring |
| **index.html** | Web dashboard (hosted on Vercel) |
| **TROUBLESHOOTING.md** | Detailed diagnostic guide |
| **QUICK_START.md** | This file |

---

## 🆘 Quick Troubleshooting

**"Upload failed"**
→ Select correct Board and COM port

**"Servo doesn't move"**
→ Check orange wire is on D9
→ Check red/brown wires have power
→ Read TROUBLESHOOTING.md

**"Serial Monitor shows nothing"**
→ Check baud rate is 115200
→ Press Arduino reset button
→ Try different USB cable

---

## 📚 Need More Help?

Read: **TROUBLESHOOTING.md** for detailed step-by-step diagnostics

Watch your Arduino's Serial Monitor output - it tells you exactly what's happening!

---

**Good luck! 🌱**
