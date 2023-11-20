#ifndef Read_console_h
#define Read_console_h

#include "Read.h"

class Read_console : public Read {
    public:
        Read_console();

        motion read_motion() override;
};

#endif