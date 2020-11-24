#include"file_handler.h"


int main(void){
    double **test = NULL; int r = 0, c = 0;

    load_file("test.csv", test, r, c);

    std::cout << test[0][0] << std::endl;

    for(int i=0; i<r; i++) delete[] test[i];
    delete[] test;

    return 0;
}