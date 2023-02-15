#include <iostream>
#include "file_handler.h"

int main(void) {
    CsvHandler DataFile("test.csv");

    std::cout << DataFile.header[0] << std::endl;
    std::cout << DataFile.content[0][0] << std::endl;

    return 0;
}