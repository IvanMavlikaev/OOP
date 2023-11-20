#ifndef Read_file_h
#define Read_file_h

#include "Read.h"
#include "fstream"
#include "Config.h"

class Read_file : public Read{
    private:
        std::ifstream r_file;
    public:
        Read_file(std::string filename);

        motion read_motion() override;

        ~Read_file();

};

#endif