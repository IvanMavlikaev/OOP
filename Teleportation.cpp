#include "Teleportation.h"
#include "Controller/Controller.h"
#include <iostream>

Teleportation::Teleportation(int x, int y) {
    this->x = x;
    this->y = y;
}

void Teleportation::do_event(Controller& control) {
    control.update_pos(this->x, this->y);
}


Teleportation* Teleportation:: clone() {
    Teleportation* teleportation = new Teleportation(*this);
    return teleportation;
}
