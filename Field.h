#ifndef Field_h
#define Field_h

#define standart_size 10

#include "Cell.h"
#include <string>

class Field{
    private:
        std::string name_room;
        int x;
        int y;
        Cell **cell_list;
        std::pair<int, int> start_pos;
        std::pair<int, int> end_pos;

    public:

        explicit Field(int x = standart_size, int y = standart_size, std::string name_room = "UNKNOWN_ROOM");

        Field(Field& other);

        Field(Field&& other);

        std:: string get_name_room();

        std::pair<int, int> get_size_field();

        void set_name_room(std::string nm);

        Cell** get_cell_list();

        void change_cell_list(int pos_x, int pos_y, passability mode);

        void print_field();

        void set_start_pos(std::pair<int, int> pos);

        std::pair<int, int> get_start_pos();

        void set_end_pos(std::pair<int, int> pos);

        std::pair<int, int> get_end_pos();

        ~Field();
};

#endif