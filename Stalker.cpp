#include "Stalker.h"
#include "Print_game.h"

Stalker::Stalker(){};

void Stalker:: handle_event(Controller* controller, Field* field, change c) {
    Print_game* print = new Print_game();
    if (c == Position) {
        controller->print_player();
        print->print_game(controller, field);
    }
    else {
        print->print_end(controller);
    }
}
