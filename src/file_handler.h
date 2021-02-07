/**
 * File Handler main module. @jpvanegasc/FileHandler
 * 
 * @author: Juan Vanegas. git: jpvanegasc
 * 
 * Last modification: Dec 8, 2020.
 */
#ifndef __FILE_HANDLER_H
#define __FILE_HANDLER_H

#include<iostream>
#include<fstream>
#include<string>
#include<vector>
#include<exception>
#include<memory>


#define vector(type) std::vector<type>
#define vector2D(type) std::vector< std::vector<type> >

#define un_ptr(type) std::unique_ptr<type>
#define un_ptr2D(type) std::unique_ptr< std::unique_ptr<type>[] >


struct FileNotOpened: public std::exception{
    const char * what() const throw () {
        return "Unable to open file";
    }
};


class FileHandler{
    private:
        un_ptr2D(double) declare_ptr(void); // change name
        void load_file(std::ifstream &file);
        void dbl_load_file();
    public:
        int columns = 0, rows = 0;

        std::unique_ptr< std::unique_ptr<std::string>[] > header;

        std::vector< std::vector<double> > content_vec;
        std::unique_ptr< std::unique_ptr<double>[] > content;

        FileHandler(std::string filename);
};


#endif // __FILE_HANDLER_H