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

/**
 * Read and write a json file
 *
 * @param filename: name or path of file.
 * @param delim_char : file data delimiter. Default is ','.
 * @param comm_char : file comment indicator. Default is '#'
 */
class JsonHandler : public FileHandler {
   public:
   std::map<std::string, std::string> json;
    void dumps(std::map<std::string, std::string> json);
    void dump(std::map<std::string, std::string> json, std::string filename);

    void loads(std::string string);
    void load(std::string filename);
};

#endif  // __JSON_HANDLER_H