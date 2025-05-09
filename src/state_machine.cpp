#include "state_machine.h"
#include "audio.h"

void StateMachine::init(DFRobotDFPlayerMini* player) {
    this->player = player;
    current = STARTUP;
    player->volume(VOLUME_STARTUP);
    player->playFolder(AUDIO_DIR, AUDIO_STARTUP);
}

void StateMachine::update(StateEvent event) {
    switch (current) {
        case STARTUP:
            if (event == EVENT_AUDIO_FINISHED) {
                current = FELIX;
                player->volume(VOLUME_SPEECH);
                player->playFolder(AUDIO_DIR, AUDIO_FELIX);
            }
            break;
        case FELIX:
            if (event == EVENT_AUDIO_FINISHED) {
                current = MORITZ;
                player->volume(VOLUME_SPEECH);
                player->playFolder(AUDIO_DIR, AUDIO_MORITZ);
            }
            break;
        case MORITZ:
         if (event == EVENT_AUDIO_FINISHED) {
                current = FELIX;
                player->volume(VOLUME_SPEECH);
                player->playFolder(AUDIO_DIR, AUDIO_FELIX);
            }
            break;
    }
}
