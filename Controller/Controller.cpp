#include "Controller.h"
#include <iostream>

Controller::Controller(Player &player, Field &field): player(player), field(field){}


void Controller::step(motion m){
    int count_step = 1;
    if (this->player.get_mode() == Run) {
        count_step ++;
    }
    switch (m){
        case Up:{
            for (int i = 0; i < count_step; i++) {
                if (this->pos.second > 0 && this->field.get_cell_list()[this->pos.first][this->pos.second - 1].get_cell_mode() == Free)  {
                    this->pos.second -= 1;
                    this->check_event();
                }
                else {
                    std:: cout << "Уперся в стенку\n";
                    break;
                }
            }
            break;
        }
        case Down:{
            for (int i = 0; i < count_step; i++) {
                if (this->field.get_size_field().second != this->pos.second + 1  && this->pos.second < this->field.get_size_field().second && this->field.get_cell_list()[this->pos.first][this->pos.second + 1].get_cell_mode() == Free )  {
                    this->pos.second += 1;
                    this->check_event();
                }
                else {
                    std:: cout << "Уперся в стенку\n";
                    break;
                }
            }
            break;
        }
        case Left:{
            for (int i = 0; i < count_step; i++) {
                if (this->pos.first > 0 && this->field.get_cell_list()[this->pos.first - 1][this->pos.second].get_cell_mode() == Free )  {
                    this->pos.first -= 1;
                    this->check_event();
                }
                else {
                    std:: cout << "Уперся в стенку\n";
                    break;
                }
            }
            break;
        }
        case Right:{
            for (int i = 0; i < count_step; i++) {
                if (this->field.get_size_field().first != this->pos.first + 1 && this->pos.first < this->field.get_size_field().first && this->field.get_cell_list()[this->pos.first + 1][this->pos.second].get_cell_mode() == Free)  {
                    this->pos.first += 1;
                    this->check_event();
                }
                else {
                    std:: cout << "Уперся в стенку\n";
                    break;
                }
            }
            break;
        }
        default:
            break;
    }
    if (this->pos.first < 0) {
        this->pos.first = 0;
    }
    if (this->pos.second < 0) {
        this->pos.second = 0;
    }
}

void Controller::update_points(int points){
    this->player.set_points(this->player.get_points() + points);
}


void Controller::update_pos(int x, int y){
    this->pos.first = x;
    this->pos.second = y;
}

void Controller::update_hp(int count) {
    this->player.set_hp(this->player.get_hp() + count);
}

void Controller::print_player(){
    std::cout << "Name:" << player.get_name() << '\n';
    std::cout << "HP: " << player.get_hp() << '\n';
    std::cout << "Points: " << player.get_points() << '\n';
    std::cout << "Mode: " << player.get_mode() << '\n';
    std::cout << "Position: " << "X: " <<pos.first << " Y: " << pos.second << '\n';
}

void Controller::check_event() { 
    if (this->field.get_cell_list()[this->pos.first][this->pos.second].get_event()) {
        this->field.get_cell_list()[this->pos.first][this->pos.second].get_event()->do_event(*this);
    }
}


int Controller::get_hp() {
    return this->player.get_hp();
}

int Controller::get_points() {
    return this->player.get_points();
}

player_mode Controller::get_mode() {
    return this->player.get_mode();
}

bool Controller :: player_dead() {
    return this->player.get_hp() == 0;
}

std::pair<int, int> Controller::get_pos() {
    return this->pos;
}