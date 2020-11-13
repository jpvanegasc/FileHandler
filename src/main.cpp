#include<iostream>
#include<fstream>
#include<string>
#include<sstream>
#include<vector>
#include<exception>


#define vector(type) std::vector<type>
#define vector2D(type) std::vector<vector(type)>


std::string get_full_file(std::ifstream f){
    std::stringstream buffer;
    buffer << f.rdbuf();
    return buffer.str();
}

struct FileNotOpened: public std::exception{
    const char * what() const throw () {
        return "Unable to open file";
    }
};


int main(void){
    char delim=',';
    std::ifstream file("test.csv");
    vector2D(double) data;

    if(file.is_open()){
        std::string line;
        while(getline(file, line)){
            std::string temp;
            vector(double) row;

            for(int i=0; i<line.size(); i++){
                char current = line[i];
                if(current != delim) temp += line[i];
                else{
                    row.push_back(std::stod(temp));
                    temp = "";
                }
            }

            row.push_back(std::stod(temp));

            data.push_back(row);
        }
    }
    else throw FileNotOpened();

    file.close();

    int n_rows = data.size(), n_columns = data[0].size();

    double **matrix = new double *[n_rows];
    for(int i=0; i<n_rows; i++)
        matrix[i] = new double[n_columns];

    for(int i=0; i<n_rows; i++)
        for(int j=0; j<n_columns; j++){
            matrix[i][j] = data[i][j];
        }

    std::cout << matrix[0][0] << std::endl;

    for(int i=0; i<n_rows; i++) delete[] matrix[i];
    delete[] matrix;

    return 0;
}