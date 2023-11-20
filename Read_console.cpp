#include "Read_console.h"
#include "iostream"
#include "Config.h"

Read_console::Read_console(){};

motion Read_console:: read_motion() {
    char x;
    std::cin >> x;
    Config config = Config();
    motion m = Stay;
    if (config.get_map_motion().count(x) > 0) {
        m = config.get_map_motion()[x];
    }
    m = config.get_map_motion()[x];
    return m;
}
