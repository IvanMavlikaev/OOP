#ifndef Stalker_h
#define Stalker_h

#include "Observer.h"


class Stalker: public Observer{
    public:
        Stalker();
        
        void handle_event(Controller* controller, Field* field, change c);
};

#endif