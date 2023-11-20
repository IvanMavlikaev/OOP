#include "Trap.h"
#include "Controller/Controller.h"
#define DAMAGE -20


Trap::Trap(){};

void Trap:: do_event(Controller& control) {
    control.update_hp(DAMAGE);
}

Trap* Trap:: clone() {
    Trap* trap = new Trap(*this);
    return trap;
}

