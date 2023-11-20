#ifndef Read_h
#define Read_h

#include "Controller/Controller.h"

class Read {
    public:
        virtual motion read_motion() = 0;
};

#endif