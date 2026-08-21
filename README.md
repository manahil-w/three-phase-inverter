# three-phase-inverter

# 3-Phase DC to AC Power Inverter (12V DC to 220V AC)

An open-source hardware and firmware implementation of a 3-phase DC-to-AC power inverter. This final design utilizes a 6-step symmetrical switching sequence and includes automated low-voltage battery protection.

## Team Members
* **Manahil Waheed**
* **Amna Sohail**
* **Emaan Imtiaz** 
* **Ahmed Jahanzeb** 
* **Haaris Mustufa Khan** 
bridge

**Course:** Electric Network Analysis | **Department:** Computer Engineering | **Date:** May 6, 2026

---

## Technical Overview
This project details the design and hardware implementation of a 3-phase inverter converting a 12V DC input to a 220V AC 3-phase output at 50 Hz. The system uses an Arduino Uno microcontroller to generate a 6-step symmetrical switching sequence (`{1,0,0}, {1,1,0}, {0,1,0}, {0,1,1}, {0,0,1}, {1,0,1}`) across digital pins D2 through D7.

To protect the connected DC power source, the firmware continuously monitors battery voltage via an analog voltage divider on pin A0. If the input drops below the 10.5V threshold, the system automatically forces all outputs `LOW` to safely shut down switching and prevent deep discharge.

## Core Hardware
The final schematic, documented in `docs/ena project.pdf`, consists of the following primary components:
* **Microcontroller:** Arduino Uno R3
* **Voltage Regulator:** LM7805C (with 1000µF and 100nF filtering capacitors)
* **Power MOSFETs:** 6× IRFZ44N (N-Channel)
* **Gate Driver Isolation:** 6× PC817 Optocouplers
* **Transformers:** 3× Center-Tapped Step-Up Transformers (`XFRM_LIN/CT-PRI`)

## Schematic & Documentation
The updated project schematic is located in the `docs/` directory (`ena project.pdf`). The hardware control buttons (Set/Reset) were removed from earlier prototypes to create a streamlined, auto-enabling inverter circuit controlled directly by software safety logic.

## References
* Mousa-Simple projects: Arduino 3-phase inverter 12V-380V
