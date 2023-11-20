#ifndef Event_h
#define Event_h

class Controller;
class Event
{
public:
    virtual void do_event(Controller &control) = 0;

    virtual Event *clone() = 0;
};

#endif