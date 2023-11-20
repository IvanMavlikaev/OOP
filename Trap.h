#ifndef Trap_h
#define Trap_h

#include "event.h"


class Trap: public Event{
    public:

        Trap();

        void do_event(Controller &conrol);

        Trap* clone();
};

#endif