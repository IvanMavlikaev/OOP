#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "../Player/Player.h"
#include "../Field.h"
#include <utility>

enum motion {Stay = 0, Up, Down, Left, Right, Stop};

class Controller {
    private:
        Player& player;
        Field& field;
        std::pair<int, int> pos;
    public:
        explicit Controller(Player& player, Field& field);
        
        void update_points(int points);

        void print_player();
        
        void step(motion m);

        void update_pos(int x, int y);
        
        void update_hp(int count);

        void check_event();

        int get_hp();

        int get_points();

        player_mode get_mode();

        bool player_dead();

        std::pair<int, int> get_pos();

        ~Controller() = default;
};

#endif
