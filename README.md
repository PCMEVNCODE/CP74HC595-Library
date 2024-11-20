CP74HC595 Library
Creator: Dev Community Project
Created on: 11/2/2024
Version: 1.0.0
----------------------------------------------------------------
Introduction:
CP74HC595 Library makes programming with IC 74HC595 and above easier for beginners to use IoT to save the number of pins plugged into the circuit board.

How to connect:

To connect the circuit board to IC 74HC595, we need to connect as follows:

--Connect VCC (5V) to pin 16 (VCC) and GND to pin 8 of IC 74HC595.

Here, we use the pins to control the circuit pins and we will use the Arduino circuit to control and you can use other circuits as well.
Example of connecting IC 74HC595 to Arduino:

--> Pin 14 (DS) connects to pin 2 (Digital) of Arduino
--> Pin 11 (SRCLK) connects to pin 3 (Digital) of Arduino
--> Pin 12 (RCLK) connects to pin 4 (Digital) of Arduino
--> Pin 10 (SRCLR) connects to VCC (5V)
--> Pin 13 (OE) connects to GND

As for the code, I put it in the examples folder.

That is a test example.

And my library supports 74HC595 ICs connected together.

Connect as follows:

The pins remain the same and the second IC will change pin 14 (DS) will connect to pin 9 (Q7') of the second IC and the pins remain connected as the first IC.

Programming and notes:

Our library only supports up to 100 pins per library declaration when pairing multiple 74HC595 ICs. IF YOU STILL DO SO, YOU MUST ACCEPT THE RISK OF OUT OF MEMORY, OVERLOADING CAUSING DAMAGE.

My library supports the following command with Ver 1.0.0:

```python

<library declaration name>.setPin(<pin number>, <High/Low>);

This is a tutorial for those who are new to circuit boards and IoT.

<Dev Community Project>-----------
