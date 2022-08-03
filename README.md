# PIEZO BUZZER USING STM32
## DESCRIPTION
- A buzzer (or Tone Alarm) can be used to audibly indicate status changes for the vehicle. Depending on board capabilities, this can be an active device (only needs voltage applied to produce a single frequency tone), as shown below, or a passive piezo device driven by PWM capable of producing variable musical tones, as shown above. Some boards can use either type.
- This project will show you how to use a buzzer with STM (*in this project:* **NUCLE0G070**) 


## HARDWARE
- [PIEZO BUZZER](https://www.digikey.com/en/products/detail/cui-devices/CPE-827/1738894)
- [NUCLE0G070](https://www.st.com/en/evaluation-tools/nucleo-g070rb.html)
- RESISTOR

## BUILD
Build and Debug in STM32CubeIDE: import the project in CubeIDE, then build

## HOW IT WORKS
We will change frequency of PWM to play notes.
![how-it-works-piezo-buzzer-music](https://user-images.githubusercontent.com/107971129/182123192-9907f261-7f3a-49c5-80b0-49bdd9ca6cb1.gif)
