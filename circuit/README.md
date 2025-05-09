# Circuit Information

## Wiring Diagram
The `schematic.png` shows how to connect all the components:
- Arduino Uno as the main controller
- DFPlayer Mini for audio playback
- Speaker for sound output
- (Two push buttons which are optional and need modification in the code)

## Connections
The project uses a simple circuit:

### DFPlayer Mini to Arduino Uno:
- VCC → 5V
- GND → GND
- RX → Digital Pin 11 (through a 1K resistor)
- TX → Digital Pin 10

### Speaker to DFPlayer Mini:
- Connect a small 3W 4 Ohm speaker to the SPK_1 and SPK_2 pins of the DFPlayer Mini

## Tips for Assembly
1. Double-check all connections before powering up
2. Use solid core wire for breadboard connections
3. If you're soldering, use heat shrink tubing to avoid short circuits
4. The DFPlayer Mini is sensitive to power issues - make sure your power supply is stable

## Power Requirements
The project can be powered through the Arduino's USB port or through the DC jack (7-12V recommended).

## Testing the Circuit
Before final assembly into the case:
1. Connect everything as shown in the schematic
2. Upload the code to the Arduino
3. Insert the SD card with your audio files
4. Power up and listen for the startup sound

If you hear the startup sound followed by the messages, your circuit is working correctly!
 