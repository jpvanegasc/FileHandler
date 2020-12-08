#include"file_handler.h"


int main(void){
    double **test = NULL; int r = 0, c = 0;

    fh::load_file("test.csv", test, r, c);
    std::cout << test[0][0] << std::endl;
    
    fh::clear(test, r);

    fh::load_file("test2.csv", test, r, c);
    std::cout << test[0][0] << std::endl;

    fh::clear(test, r, false);

    return 0;
}