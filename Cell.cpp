#include "Cell.h"



Cell::Cell(passability mode){
    this->mode = mode;
}

Cell::Cell(const Cell& other){
    this->mode = other.mode;
}

Cell &Cell::operator =(const Cell &other) {
    if (this == &other) {
        return *this;
    }
    this->mode = other.mode;
    return *this;
}

passability  Cell::get_cell_mode() {
    return this->mode;
}

void  Cell::set_cell_mode(passability mode) {
    this->mode = mode;
}

void Cell :: set_cell_event(Event* event) {
    this->event = event->clone();
}


Event* Cell :: get_event() {
    return this->event;
}