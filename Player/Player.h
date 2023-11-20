#ifndef Player_h
#define Player_h
#include <string>

enum player_mode {Usual, Run, Quiet};

class Player{
    private:
        std::string name;
        int hp;
        int points;
        player_mode mode;

    public:
        explicit Player(std::string name = "UNKNOWN_PLAYER");

        std:: string get_name();

        void set_name(std::string nm);

        int get_hp();

        void set_hp(int hp);

        int get_points();

        void set_points(int points);

        player_mode get_mode();

        void set_mode(player_mode mode);

        ~Player() = default;
};


#endif