#ifndef Print_game_h
#define Print_game_h

#include "Controller/Controller.h"
#include "Field.h"

class Print_game {
    public:
        Print_game();
        
        void print_game(Controller* controller, Field* field);

        void print_end(Controller* controller);
};

#endif