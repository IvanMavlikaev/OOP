#ifndef Observable_h
#define Observable_h

#include "Observer.h"

class Observable {
    public:
        
        virtual void add_observer(Observer *observer) = 0;

        virtual void remove_observer(Observer *observer) = 0;

        virtual void update(change c) = 0;
};

#endif