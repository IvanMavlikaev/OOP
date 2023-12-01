#ifndef Game_h
#define Game_h

#include "Observable.h"
#include "Player/Player.h"
#include "Fieldmaker.h"
#include "Cell.h"
#include <iostream>
#include <vector>
#include "Stalker.h"
#include "Read.h"
#include "Read_console.h"
#include "Read_file.h"
#include "Print_game.h"



class Game : public Observable {
    private:
        Field *field;
        Controller *controller;
        std :: vector<Observer*> observers;
    public:

        Game();

        void start_game();
        
        void game();

        void end_game();

        void add_observer(Observer *observer);

        void remove_observer(Observer *observer);

        void update(change c);
};

#endif