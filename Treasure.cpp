#include "Treasure.h"
#include "Controller/Controller.h"

#define MONEY 10

Treasure::Treasure(){};

void Treasure::do_event(Controller& control) {
    control.update_points(MONEY);
}


Treasure* Treasure:: clone() {
    Treasure* treasure = new Treasure(*this);
    return treasure;
}
