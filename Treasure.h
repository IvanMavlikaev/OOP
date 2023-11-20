#ifndef Treasure_h
#define Treasure_h

#include "event.h"

#include "Controller/Controller.h"

class Treasure : public Event{
    public:
        Treasure();
        
        void do_event(Controller &conrol);

        Treasure* clone();
};

#endif