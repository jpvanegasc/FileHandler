#include "file_handler.h"

FileHandler::FileHandler(std::string filename, char delimiter_char, char comment_char){
    std::ifstream file(filename);

    delimiter = delimiter_char;
    comment = comment_char;

    if(file.is_open()){
        load_file(file);
    }
    else throw FileNotOpened();

    file.close();
}

void FileHandler::read_line(const std::string &line, vector(std::string) &row){
    std::string temp; int start = 0;
    row.clear();

    if(line[0] == comment) start = 1;

    for(unsigned int i=start; i<line.size(); i++){
        char current = line[i];

        if(current != delimiter) temp += line[i];
        else{
            row.push_back(temp);
            temp = "";
        }
    }

}

void FileHandler::load_file(std::ifstream &file){
    std::string line;

    int line_num = 0;

    while(getline(file, line)){
        if(line[0] != comment){
            vector(std::string) str_row; vector(double) row;
            read_line(line, str_row);

            if(line_num == 0) columns = str_row.size();

            for(unsigned int i=0; i<str_row.size(); i++) row.push_back(std::stod(str_row[i]));
            content.push_back(row);
        }
        else if(line_num == 0){
            read_line(line, header);
            columns = header.size();
        }

        line_num++;
    }

    rows = line_num;
}

// data must be null!
void FileHandler::content_to_double(double **&data){
    data = new double *[rows];
    for(int i=0; i<columns; i++) data[i] = new double;

    for(int i=0; i<rows; i++)
        for(int j=0; j<columns; j++)
            data[i][j] = content[i][j];
}


#undef vector2D
#undef vector
