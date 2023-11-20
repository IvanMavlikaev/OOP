#ifndef Cell_h
#define Cell_h

#include "event.h"

enum passability{Free, Solid, Slow};

class Cell {
    private:
        passability mode;

        Event* event;

    public:

        explicit Cell(passability mode = Free);

        Cell(const Cell& other);

        Cell &operator = (const Cell &other);

        passability get_cell_mode();
        
        void set_cell_mode(passability mode);

        Event* get_event();

        void set_cell_event(Event *event);

        ~Cell() = default;
};

#endif