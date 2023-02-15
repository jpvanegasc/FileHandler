/**
 * Json Handler main module. @jpvanegasc/FileHandler
 *
 * @author: Juan Vanegas. git: jpvanegasc
 *
 * Last modification: Feb 8, 2021.
 */
#ifndef __FILE_HANDLER_H
#define __FILE_HANDLER_H

#include <cmath>
#include <exception>
#include <fstream>
#include <iostream>
#include <memory>
#include <sstream>
#include <string>
#include <vector>

#define vector(type) std::vector<type>
#define vector2D(type) std::vector<std::vector<type>>

struct FileNotOpened : public std::exception {
    const char *what() const throw() {
        return "Unable to open file";
    }
};

/**
 * Mixin to read and write a file
 *
 * @param filename: name or path of file.
 */
class FileHandler {
   public:
    std::string content;
    void read_file(std::string filename);
    void write_file(std::string filename);
};

#endif  // __FILE_HANDLER_H