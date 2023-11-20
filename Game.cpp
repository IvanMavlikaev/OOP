#include "Game.h"
#include "fstream"
#include "Read.h"
#include "Read_console.h"
#include "Read_file.h"

#define size_x 8
#define size_y 8

void Game::start_game() {
    std::string name;
    int x, y, number_level, input;
    std::cout << "Введите имя игрока" << '\n';
    std::cin >> name;
    std::cout << "Управление игроком осуществляется при помощи клавиш W - вверх, A - влево, S - вниз, D - вправо\n";
    std::cout << "Выберите уровень - 1 или 2, введите одно число\n";
    std::cin >> number_level;
    Fieldmaker *fieldmaker = new Fieldmaker();
    if (number_level == 1) {
        this->field = fieldmaker->generate_field_level(size_x, size_y, "level1.txt");
    }
    else if (number_level == 2) {
            this->field = fieldmaker->generate_field_level(size_x, size_y, "level2.txt");
        }
        else {
            std::cout << "Uncorrect number of level\n";
            return;
        }
    this->field->print_field();
    this->controller = new Controller(*new Player(name), *field);
    this->controller->print_player();
    this->game();
}

void Game::game() {
    std::cout << "Выберите, как вы будете вводить данные - напишите 1 если в консоли, напишите 2 если в файле. Если в файле то введите имя файла\n";
    int input;
    std::cin >> input;
    if (input == 1) {
        motion m;
        Read *read = new Read_console();
        while (!this->controller->player_dead()) {
            if (this->controller->get_pos() == this->field->get_end_pos()) {
                break;
            }
            m = read->read_motion();
            this->controller->step(m);
            this->controller->print_player();
            this->field->print_field();
        }
    }
    else if (input == 2) {
        motion m;
        std::string filename;
        std::cin >> filename;
        Read *read = new Read_file(filename);
        while (!this->controller->player_dead() ) {
            if (this->controller->get_pos() == this->field->get_end_pos()) {
                break;
            }
            m = Stay;
            m = read->read_motion();
            if (m == Stop) {
                std::cout << "Вы не вышли из лабиринта\n";
                return;
            }
            this->controller->step(m);
            this->controller->print_player();
            this->field->print_field();
        }
    }
    else {
        std::cout << "Error with choice thret\n";
        return;
    }
    this->end_game();
}

void Game::end_game() {
    if (this->controller->player_dead()) 
        std::cout << "YOU LOST\n";
    else {
        std::cout << "YOU WIN\n";
    }
    std::cout << "Если вы хотите начать новую игру, введите Y\n";
    char c;
    std::cin>> c;
    if (c == 'Y') {
        this->start_game();
    }
}