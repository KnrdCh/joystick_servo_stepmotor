# 🕹️ Joystick-Controlled Servo and Stepper Motor (Arduino)

This project allows you to control both a **servo motor** (for steering) and a **stepper motor** (for movement direction) using a **joystick**.  
It demonstrates the basics of analog input reading and motor control with Arduino.

---

## 🧠 Description

- The **joystick’s X-axis** controls the **servo motor**, allowing you to steer left and right.  
- The **joystick’s Y-axis** controls the **stepper motor**, driving it **forward** or **backward**.  
- The system reads analog joystick inputs from pins **A0** and **A1**.  
- Four digital pins (10–13) drive the stepper motor coils in sequence.

---

## ⚙️ Hardware Requirements

- Arduino UNO / Nano or compatible board  
- Joystick module (2-axis analog joystick)  
- Servo motor (e.g., SG90 or MG995)  
- 4-step unipolar stepper motor (e.g., 28BYJ-48)  
- ULN2003 driver module (optional but recommended)  
- Jumper wires and breadboard  

---

## 🔌 Connections

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| Joystick X-axis | A0 | Controls servo angle |
| Joystick Y-axis | A1 | Controls movement direction |
| Servo signal | D9 | Servo control pin |
| Stepper motor coil 1 | D10 | Stepper driver output 1 |
| Stepper motor coil 2 | D11 | Stepper driver output 2 |
| Stepper motor coil 3 | D12 | Stepper driver output 3 |
| Stepper motor coil 4 | D13 | Stepper driver output 4 |
| Joystick VCC | 5V | Power supply |
| Joystick GND | GND | Ground |

---

## 💻 Code Overview

```cpp
#include <Servo.h>
#define XPIN A0
#define YPIN A1
#define P1 10
#define P2 11
#define P3 12
#define P4 13

Servo servo_9;

float position;
float valueX;

void setup() {
  Serial.begin(9600);
  servo_9.attach(9, 500, 2500);

  pinMode(XPIN, INPUT);
  pinMode(YPIN, INPUT);
  pinMode(P1, OUTPUT);
  pinMode(P2, OUTPUT);
  pinMode(P3, OUTPUT);
  pinMode(P4, OUTPUT);
}

void loop() {
  if (analogRead(YPIN) > 530) {
    forward(2);
  } else if (analogRead(YPIN) < 510) {
    backward(2);
  }

  valueX = analogRead(XPIN);
  position = (valueX / 1023.0) * 180;
  servo_9.write(position);
}

void forward(int delayTime) {
  digitalWrite(P1, HIGH); delay(delayTime); digitalWrite(P1, LOW);
  digitalWrite(P2, HIGH); delay(delayTime); digitalWrite(P2, LOW);
  digitalWrite(P3, HIGH); delay(delayTime); digitalWrite(P3, LOW);
  digitalWrite(P4, HIGH); delay(delayTime); digitalWrite(P4, LOW);
}

void backward(int delayTime) {
  digitalWrite(P4, HIGH); delay(delayTime); digitalWrite(P4, LOW);
  digitalWrite(P3, HIGH); delay(delayTime); digitalWrite(P3, LOW);
  digitalWrite(P2, HIGH); delay(delayTime); digitalWrite(P2, LOW);
  digitalWrite(P1, HIGH); delay(delayTime); digitalWrite(P1, LOW);
}
