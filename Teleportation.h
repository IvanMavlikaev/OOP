#ifndef Teleportation_h
#define Teleportation_h

#include "event.h"


class Teleportation : public Event{
    private:
        int x;
        int y;
    public:
        Teleportation(int x, int y);

        void do_event(Controller &conrol);

        Teleportation* clone();
};

#endif