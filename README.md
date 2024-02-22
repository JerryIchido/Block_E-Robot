# Block_E-Robot
This is the code for UCLA HAcK 2022 Competition, in which we are required to build a robot capable of picking up two different kinds of parts and place in backpack. 
Also 
The code for the robot consists of three files: Processing based input code to transmit commands from computer to ESP32;  
Code for ESP32 which is just transmitting the command from the Bluetooth tunnel to the Arduino.
The main controlling code is based on Arduino. 

The Arduino-based code consists of: Three servos, four motors, and one LCD screen. The pins are also specified so there may be some referential value.

However, to make things smoother, you may want to delete all the Serial prints as they completely halt the code!
