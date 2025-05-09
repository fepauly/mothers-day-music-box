#ifndef STATE_MACHINE_H
#define STATE_MACHINE_H

#include "DFRobotDFPlayerMini.h"

enum State {
    STARTUP,
    FELIX,
    MORITZ
};

enum StateEvent {
    EVENT_NONE = 0,
    EVENT_AUDIO_FINISHED,
};

class StateMachine {
public:
    State current;
    DFRobotDFPlayerMini* player;
    void init(DFRobotDFPlayerMini* player);
    void update(StateEvent event);
};

#endif // STATE_MACHINE_H
