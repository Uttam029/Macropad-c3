# Custom ESP32-C3 Wireless Bluetooth MacroPad

A custom, wireless Bluetooth Low Energy (BLE) macro keypad featuring Cherry MX mechanical switches, a KY-040 rotary encoder, and an SSD1306 128x64 OLED display, powered by a 3.7V LiPo battery with USB-C charging.

---

## Project Structure

```
macro pad/
├── hardware/               # KiCad 8.0 / 10.0 Hardware Design Files
│   ├── Macropad.kicad_pro  # KiCad Project File
│   ├── Macropad.kicad_sch  # Schematic (2x2 Matrix, OLED, Encoder, MCU)
│   ├── Macropad.kicad_pcb  # 2-Layer PCB Layout
│   ├── Macropad.step       # 3D CAD STEP Model of Assembled Board
│   ├── BOM.txt             # Bill of Materials
│   └── libraries/          # Custom Footprints and 3D Models
│
└── firmware/               # Arduino / PlatformIO Firmware
    ├── code.ino            # Main Loop & Deep-Sleep Power Management
    ├── pins.h              # Pin Definitions (Matrix, Encoder, OLED)
    ├── functions.h / .cpp  # Matrix Scanning & Encoder Logic
    ├── keystroke.h / .cpp  # BLE HID Keycode / Shortcut Actions
    └── screen.h / .cpp     # SSD1306 U8g2 Display UI Rendering
```

---

## Hardware Specifications

* **Microcontroller:** ESP32-C3 RISC-V SoC (BLE 5.0, low-power deep sleep)
* **Keys:** 4x Mechanical Cherry MX / Gateron switches (2x2 matrix with 1N4148 diodes)
* **Rotary Knob:** KY-040 rotary encoder with push-button (scrolling, volume, brush control)
* **Display:** 0.96" SSD1306 I2C OLED (128x64) with live layer & keypress feedback
* **Power:** 3.7V LiPo battery with USB-C charging management

---

## Required Firmware Libraries

Install via the Arduino IDE Library Manager or PlatformIO:
* `ESP32-BLE-Combo` (or `ESP32-BLE-Keyboard`)
* `Encoder` by Paul Stoffregen
* `u8g2` by olikraus
