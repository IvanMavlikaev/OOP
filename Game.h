#ifndef Game_h
#define Game_h

#include "Controller/Controller.h"
#include "Player/Player.h"
#include "Field.h"
#include "Fieldmaker.h"
#include "Cell.h"
#include <iostream>

class Game{
    private:
        Field *field;
        Controller *controller;
    public:
        void start_game();
        
        void game();

        void end_game();
};

#endif