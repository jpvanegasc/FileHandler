#include "json_handler.h"

void FileHandler::read_file(std::string filename) {
    std::ifstream file(filename);

    if (file.is_open()) {
        std::stringstream buffer;
        buffer << file.rdbuf();
        content = buffer.str();
    } else
        throw FileNotOpened();

    file.close();
}

void FileHandler::write_file(std::string filename) {
    std::ofstream file(filename);
    file << content;
    file.close();
}