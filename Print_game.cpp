#include "Print_game.h"
#include <iostream>
#include "Trap.h"
#include "Treasure.h"
#include "Teleportation.h"

Print_game::Print_game(){}

void Print_game::print_game(Controller* controller, Field* field) {
    std::cout << '.';
    int x = field->get_size_field().first;
    int y = field->get_size_field().second;
    for (int j = 0; j < x; j++) {
            std::cout << ".___.";
    }
    std::cout << '.';
    for (int i = 0; i < y; i++) {
        std:: cout << std::endl << '|';
        for (int j = 0; j < x; j++) {
            if (!field->get_cell_list()[j][i].get_cell_mode() && !field->get_cell_list()[j][i].get_event() && !(controller->get_pos().first == j && controller->get_pos().second == i)) {
                std::cout << ":   :";
            }
            else {
                if (controller->get_pos().first == j && controller->get_pos().second == i) {
                    std::cout << ": x :";
                }
                else {
                    if (!field->get_cell_list()[j][i].get_cell_mode() && field->get_cell_list()[j][i].get_event()) {
                        Event *event = field->get_cell_list()[j][i].get_event();
                        if (dynamic_cast<Trap*>(event)) {
                            std::cout << ": # :";
                        }
                        else {
                            if (dynamic_cast<Treasure*>(event)) {
                                std::cout << ": $ :";
                            }
                            else {
                                if (dynamic_cast<Teleportation*>(event)) {
                                    std::cout << ": o :";
                                }
                                else {
                                    std::cout << ":   :";
                                }
                            }
                        }
                    }
                    else {
                        std::cout << ":::::";
                    }
                }
            }
        }
        std:: cout << '|' <<  std::endl << '.';
        for (int j = 0; j < x; j++) {
            if (!field->get_cell_list()[j][i].get_cell_mode()) {
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

void Print_game :: print_end(Controller* controller) {
    if (controller->player_dead()) 
        std::cout << "YOU LOST\n";
    else {
        std::cout << "YOU WIN\n";
    }
    std::cout << "Если вы хотите начать новую игру, введите Y\n";
}