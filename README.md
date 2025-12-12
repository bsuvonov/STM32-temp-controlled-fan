## STM32F103 based Temperature Sensitive Fan (LM35 temperature sensor + DFROBOT MOSFET + Buzzer)

Authors: Bunyod Suvonov, Wee Keat Lim

Minimal firmware for STM32F103C8 that reads an LM35 temperature sensor on `PB0`, switches a 5 V fan through a MOSFET on/off via `PB1`, and drives a KY-012 buzzer on `PB2`. The fan is **off below ~30 °C** and **fully on at ≥30 °C**; the buzzer asserts at ≥40 °C (both with a small hysteresis).

<img width="2394" height="1531" alt="Screenshot From 2025-12-12 21-52-28" src="https://github.com/user-attachments/assets/919dab0e-ed61-455c-bb14-a53641ff1ccc" />


## Wiring Summary

- **LM35**: Left=3.3 V, Middle=`PB0` (ADC1_IN8), Right=GND. Flat side toward you.
- **MOSFET module (DFR0457 or logic-level N-FET)**  
  - Logic: Red=3.3 V, Black=GND, Green=SIG→`PB1`.  
  - Load: VIN=stable 5 V input, VOUT→fan red (+), GND→fan black (–) + common GND.
- **Fan (5 V)**: Red→MOSFET VOUT, Black→common GND. Use an external 5 V supply (not ST-LINK 5 V).
- **Buzzer (KY-012)**: S→`PB2`, +→5 V, –→GND.
- **Power**: 3.3 V to LM35 and MOSFET logic; 5 V to fan VIN and buzzer +. **All grounds common** (STM32, MOSFET logic/load, fan, LM35, buzzer).

## Firmware Behavior

- LM35 sampled with ADC1 on `PB0`, averaged (16 samples).  
- Fan (`PB1`): GPIO on/off. Off below ~29 °C (30 °C – 1 °C hysteresis), ON at ≥30 °C.  
- Buzzer (`PB2`): ON at ≥40 °C, OFF below (40 °C – 1 °C).  
- LCD shows temperature and fan/buzzer state.

## Build & Flash

```bash
cd Debug
make main-build
arm-none-eabi-objcopy -O binary Lab3.elf Lab3.bin
st-flash --reset write Lab3.bin 0x08000000
```
If `st-flash` warns about libusb, unplug/replug ST-LINK and retry. NRST is not connected, so `st-flash` uses software reset.


### Watch demo here:


<a href="https://youtu.be/lh_6Y_hIUkY" target="_blank">
 <img src="https://github.com/user-attachments/assets/9dd8673f-689b-4619-95de-be1e3acd093e" alt="Watch the game demo" width="3296" height="1854" border="10" />
</a>
