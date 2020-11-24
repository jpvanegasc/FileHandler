#include "file_handler.h"


std::string get_full_file(std::ifstream f){
    std::stringstream buffer;
    buffer << f.rdbuf();
    return buffer.str();
}

void load_file(std::string filename, double **&data, int &rows, int &columns, char delim){
    std::ifstream file("test.csv");
    vector2D(double) data_vec;

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

            data_vec.push_back(row);
        }
    }
    else throw FileNotOpened();

    file.close();

    int n_rows = data_vec.size(), n_columns = data_vec[0].size();

    data = new double *[n_rows];
    for(int i=0; i<n_rows; i++)
        data[i] = new double[n_columns];

    for(int i=0; i<n_rows; i++)
        for(int j=0; j<n_columns; j++){
            data[i][j] = data_vec[i][j];
        }

    rows = n_rows; columns = n_columns;

}
