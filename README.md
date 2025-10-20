# 🎮 Servo and Stepper Motor Control with Joystick (Arduino)

This project allows you to control both the **steering direction of a servo motor** and the **movement direction of a stepper motor** using an **analog joystick**.  
The code is written in Arduino IDE and uses the `Servo.h` library.

---

## 🧠 Description

- The **X-axis** of the joystick (connected to pin `A0`) controls the **servo position** – i.e., the steering angle.  
- The **Y-axis** of the joystick (connected to pin `A1`) controls the **movement direction**:
  - Moving the joystick **forward** runs the function `przod()` (forward)
  - Moving it **backward** runs the function `wsteczny()` (reverse)
  - In the **center position**, the motor stops

Joystick values are read using `analogRead()`, and the servo angle is calculated in the range **0–180°**.

---

## ⚙️ Hardware Requirements

- Arduino UNO / Nano or compatible board  
- Analog joystick (2-axis)  
- Servo motor (e.g. SG90 or MG90S)  
- Stepper motor with driver (e.g. ULN2003)  
- Jumper wires  

---

## 🔌 Connections

| Component | Arduino Pin | Description |
|------------|--------------|-------------|
| Joystick X | A0 | Controls servo angle |
| Joystick Y | A1 | Controls stepper direction |
| Servo signal | D9 | Servo control pin |
| Stepper IN1 | D10 | Coil 1 |
| Stepper IN2 | D11 | Coil 2 |
| Stepper IN3 | D12 | Coil 3 |
| Stepper IN4 | D13 | Coil 4 |
| Power | 5V / GND | Common ground and power |

---

## 🪄 How It Works

1. The joystick values are continuously read from analog pins A0 and A1.  
2. The Y-axis determines stepper motor rotation direction:
   - >530 → forward (`przod()`)
   - <510 → reverse (`wsteczny()`)
   - in between → stop
3. The X-axis is converted to an angle (0–180°) and sent to the servo.

---

## 🧰 Main Functions

- `przod(int dly)` – rotates the stepper motor forward with delay `dly` between steps  
- `wsteczny(int dly)` – rotates the stepper motor backward  
- `servo_9.write(pozycja)` – sets the servo position based on joystick input  

---

## 🚀 Usage

1. Open the `.ino` file in **Arduino IDE**  
2. Select the correct board and COM port  
3. Upload the sketch to your Arduino  
4. Move the joystick:
   - X-axis → servo steering  
   - Y-axis → stepper motor forward/reverse  
