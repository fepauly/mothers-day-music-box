#include "state_machine.h"
#include "audio.h"

void StateMachine::init(DFRobotDFPlayerMini* player) {
    this->player = player;
    current = STARTUP;
    player->volume(30);
    player->playFolder(AUDIO_DIR, AUDIO_STARTUP);
}

void StateMachine::update(StateEvent event) {
    switch (current) {
        case STARTUP:
            if (event == EVENT_AUDIO_FINISHED) {
                current = GREETING;
                player->volume(22);
                player->playFolder(AUDIO_DIR, AUDIO_HELLO);
            }
            break;
        case GREETING:
            if (event == EVENT_AUDIO_FINISHED) {
                current = WAIT_INPUT;
            }
            break;
        case WAIT_INPUT:
            if (event == EVENT_BUTTON_YES) {
                // Handle YES button pressed
                current = STARTUP;
                player->volume(30);
                player->playFolder(AUDIO_DIR, AUDIO_STARTUP);
            } else if (event == EVENT_BUTTON_NO) {
                // Handle NO button pressed
            }
            break;
    }
}
