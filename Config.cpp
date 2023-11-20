#include "Config.h"
#include "fstream"
#include "iostream"

Config::Config(){
    std::ifstream in("keys.txt");
    char c;
    motion m;
    std::map <char, motion> map_motion = {};
    if (in.is_open()) {
        in >> c;
        map_motion[c] = Up;
        in >> c;
        map_motion[c] = Down;
        in >> c;
        map_motion[c] = Left;
        in >> c;
        map_motion[c] = Right;
        in >> c;
        map_motion[c] = Stop;
    }
    if (map_motion.size() != 5) {
        std::cout <<"Неверный файл с ключами";
        throw "problem";
    }
    
    this->map_motion = map_motion;
    in.close();
};

std::map <char, motion> Config :: get_map_motion() {
    return this->map_motion;
};