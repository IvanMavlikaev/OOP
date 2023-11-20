#include "Fieldmaker.h"
#include <fstream>
#include <iostream>
#include "Trap.h"

#include "Treasure.h"
#include "Teleportation.h"

Fieldmaker::Fieldmaker() {};  

Field* Fieldmaker :: generate_field_level(int x, int y, std :: string name_file) {
    Field *field = new Field(x, y);
    field->set_start_pos(std::make_pair(0, 0)); 
    field->set_end_pos(std::make_pair(x - 1, y - 1));
    std::ifstream in(name_file);
    if (in.is_open()) {
        int count_solid, count_trap, count_treasure, count_teleportation;
        in >> count_solid;
        int x_object, y_object;
        for (int i = 0; i < count_solid; i++) {
            in >> x_object >> y_object;
            field->change_cell_list(x_object * x / 8, y_object * y / 8, Solid);
        }
        Trap *trap = new Trap();
        Treasure *treasure = new Treasure();
        Teleportation *teleportation = new Teleportation(0, 0);
        in >> count_trap;
        for (int i = 0; i < count_trap; i++) {
            in >> x_object >> y_object;
            field->get_cell_list()[x_object][y_object].set_cell_event(trap);
        }
        in >> count_treasure;
        for (int i = 0; i < count_treasure; i++) {
            in >> x_object >> y_object;
            field->get_cell_list()[x_object][y_object].set_cell_event(treasure);
        }
        in >> count_teleportation;
        for (int i = 0; i < count_teleportation; i++) {
            in >> x_object >> y_object;
            field->get_cell_list()[x_object][y_object].set_cell_event(teleportation);
        }
    }
    in.close();
    return field;
}

