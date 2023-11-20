#ifndef Fieldmaker_h
#define Fieldmaker_h

#include "Field.h"

class Fieldmaker{
    public:
        Fieldmaker();

        Field* generate_field_level(int x, int y, std::string file_name);
};

#endif