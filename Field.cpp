#include "Field.h"
#include <iostream>
#include "Trap.h"
#define min_size 8
#define max_size 20


Field::Field(int x, int y, std::string name_room){
    if (x < min_size || y < min_size || x > max_size || y > max_size) {
        throw "Vertical and horisontal sizes of the field must be between 8 and 20";
    }
    Cell** cell_list = new Cell * [x];
    for (int i = 0; i < x; i++) {
        cell_list[i] = new Cell[y];
    }
    this->x = x;
    this->y = y;
    this->cell_list = cell_list;
    this->name_room = "UNKNOWN_ROOM";
    this->set_start_pos(std::make_pair(0, 0)); 
    this->set_end_pos(std::make_pair(x - 1, y - 1)); 
}


Field::Field(Field& other){
    x = other.x;
    y = other.y;
    name_room = other.name_room;
    start_pos = other.start_pos;
    end_pos = other.end_pos;
    cell_list = new Cell*[x];
    for (int i = 0; i < x; i++) {
        cell_list[i] = new Cell[y];
    }
    for (int i = 0; i < x; i++) {
        for (int j = 0; j < y; j++) {
            cell_list[i][j] = other.cell_list[i][j];
        }
    }

}


Field::Field(Field&& other)
    : x(other.x)
    , y(other.y)
    , name_room(other.name_room)
    , start_pos(other.start_pos)
    , end_pos(other.end_pos)
    , cell_list(other.cell_list) 
    {
    other.cell_list = nullptr;
    }


std::string Field:: get_name_room() {
    return this->name_room;
}

std::pair<int, int> Field :: get_size_field() {
    return std::make_pair(this->x, this->y);
}

void Field:: set_name_room(std::string name) {
    this->name_room = name;
}

Cell** Field::get_cell_list() {
    return this->cell_list;
}


void Field:: change_cell_list(int pos_x, int pos_y, passability mode) {
    if (pos_x < 0 && pos_y < 0) {
        throw "position of the cell must be >= 0";
    }
    this->cell_list[pos_x][pos_y].set_cell_mode(mode);
}


Field :: ~Field() {
    for (int i = 0; i < this->x; i++ ) {
        delete[] this->cell_list[i];
    }
    delete[] this->cell_list;
}


void Field :: print_field() {
    std::cout << '.';
    for (int j = 0; j < x; j++) {
            std::cout << ".___.";
    }
    std::cout << '.';
    for (int i = 0; i < y; i++) {
        std:: cout << std::endl << '|';
        for (int j = 0; j < x; j++) {
            if (!this->get_cell_list()[j][i].get_cell_mode() && !this->get_cell_list()[j][i].get_event()) {
                std::cout << ":   :";
            }
            else {
                if (!this->get_cell_list()[j][i].get_cell_mode() && this->get_cell_list()[j][i].get_event()) {
                    std::cout << ": o :";
                }
                else {
                    std::cout << ":::::";
                }
            }
        }
        std:: cout << '|' <<  std::endl << '.';
        for (int j = 0; j < x; j++) {
            if (!this->get_cell_list()[j][i].get_cell_mode()) {
                std::cout << ":...:";
            }
            else {
                std::cout << ":::::";
            }
        }
        std:: cout << '.';
    }
    std::cout << '\n';
    std::cout << '`';
    for (int j = 0; j < x; j++) {
            std::cout << "`````";
    }
    std::cout << '`';
    std::cout << '\n';
}

void Field :: set_start_pos(std::pair<int, int> pos) {
    this->start_pos = pos;
}

std::pair<int, int> Field:: get_start_pos() {
    return this-> start_pos;
}

void Field:: set_end_pos(std::pair<int, int> pos) {
    this->end_pos = pos;
}

std::pair<int, int> Field:: get_end_pos() {
    return this->end_pos;
}