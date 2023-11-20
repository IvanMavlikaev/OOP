#include "Read_file.h"
#include "Config.h"
#include <iostream>

Read_file::Read_file(std::string filename): r_file(filename) {};


motion Read_file :: read_motion() {
        char c;
        this->r_file >> c;
        motion m = Stay;
        Config config = Config();
        if (config.get_map_motion().find(c) != config.get_map_motion().end()) {
            m = config.get_map_motion()[c];
        }
        return m;
    }

Read_file :: ~Read_file() {
    this->r_file.close();
}