#include "Player.h"


Player::Player(std::string name){
    if(name.size() == 0){
        throw "name can`t be an empty string";
    }
    this->name = name;
    this->hp = 100;
    this->points = 0;
    this->mode = Usual;
}

std::string Player::get_name() {
    return this->name;
}

void Player::set_name(std::string name) {
    this->name = name;
}

int Player::get_hp() {
    return this->hp;
}

int Player::get_points() {
    return this->points;
}

void Player::set_hp(int hp){
    if (hp < 0){
        this->hp = 0;
    }
    else{
        this->hp = hp;
    }
}

void Player::set_points(int points){
    if (points < 0){
        this->points = 0;
    }
    else{
        this->points = points;
    }
}

player_mode Player::get_mode() {
    return this->mode;
}

void Player::set_mode(player_mode mode) {
    this->mode = mode;
}
