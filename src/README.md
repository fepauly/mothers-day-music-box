# Code Documentation

This folder contains all the code that makes the Mother's Day Music Box work. Here's a breakdown of how it all fits together!

## Main Components

### main.cpp
This is the main Arduino program that:
- Sets up the serial connection to the DFPlayer Mini
- Initializes the state machine
- Listens for when audio finishes playing and triggers the next state

### state_machine.cpp & state_machine.h
These files handle the "brains" of the project:
- Define the different states (STARTUP, FELIX, MORITZ)
- Control which audio file plays in each state
- Handle transitions between states when audio finishes

### audio.h
This file contains constants for:
- Which audio files to play
- What folder the files are stored in
- Volume levels for different types of audio

## How the Code Works
The system is super simple - it's basically just playing audio files in sequence:

1. When powered on, it plays the startup sound (001.mp3)
2. After the startup sound finishes, it plays my message (002.mp3)
3. When Felix's message is done, it plays my brothers message (003.mp3)
4. After Moritz's message, it loops back to me again
5. This continues until power is turned off

The DFPlayer library handles all the heavy lifting of playing the MP3 files, and our state machine just keeps track of where we are in the sequence.

## Modifying the Code
Want to change how it works? Here are some easy modifications:

- To change the volume, edit the `VOLUME_STARTUP` and `VOLUME_SPEECH` constants in `audio.h`
- To add more messages, add more states to the `State` enum in `state_machine.h` and update the state transitions in `state_machine.cpp`
- To change the playback order, modify the transition order in `state_machine.cpp`

## Required Libraries
- SoftwareSerial (comes with Arduino IDE)
- DFRobotDFPlayerMini (install via Arduino Library Manager)
