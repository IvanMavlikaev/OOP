#ifndef Observer_h
#define Observer_h

#include "Controller/Controller.h"
#include "Field.h"

enum change {Position, End, Event_done};

class Observer {
    public:
        virtual void handle_event(Controller* controller, Field* field, change c) = 0;
};

#endif