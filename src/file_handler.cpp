#include "file_handler.h"

FileHandler::FileHandler(std::string filename){
    std::ifstream file(filename);

    if(file.is_open()){
        load_file(file);
    }
    else throw FileNotOpened();

    file.close();

    declare_ptr();

    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            content[i][j] = content_vec[i][j];
}

#undef vector2D
#undef vector

#undef un_ptr
#undef un_ptr2D
