#ifndef Config_h
#define Config_h

#include "Controller/Controller.h"
#include <map>

class Config {
    private:
        std::map <char, motion> map_motion = {};
    
    public:
        Config();
        std::map <char, motion> get_map_motion();
};

#endif