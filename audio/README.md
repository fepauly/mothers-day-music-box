# Audio Files

## What goes here?
This is where you'll place the MP3 files for the music box. The files aren't included in the repository for privacy reasons, but here's how to set up your own:

## SD Card Structure
The DFPlayer Mini expects a specific folder structure on the SD card:

```
/01/
  001.mp3  # Startup sound
  002.mp3  # My message
  003.mp3  # My brothers message
```

## Recording Tips
1. Keep the messages short and sweet (30-60 seconds is ideal)
2. Use a quiet room to minimize background noise
3. Speak clearly and not too fast
4. Add a short pause at the beginning and end of each recording
5. Save files in MP3 format (max. 128 kbps recommended)

## How to Prepare Your SD Card
1. Format your SD card as FAT32
2. Create a folder named "01" on the root of the SD card
3. Name your audio files sequentially as shown above
4. Copy them to the "01" folder
5. Insert the SD card into the DFPlayer Mini module

The state machine is programmed to play 001.mp3 at startup, then 002.mp3 (My message), followed by 003.mp3 (My brothers message), and then loop back to my message. You can easily modify the state machine and add your own logic.
