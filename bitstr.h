#pragma once
#include <string>
#include <fstream>
using namespace std;

class BitStr {
  private:
    bool* arr1;
    bool* arr2;
    bool* arr_con;
    bool* arr_tmp;
    int len;
    int max;
    int min;
    string line;
    char type_read;
    char type_write;
    string tmp1 = "";
    string tmp2 = "";
    string file_read;
    string file_write;
  public:
    BitStr(string file_read, string file_write);
    BitStr();
    char get_typer();
    char get_typew();
    void print_array(bool* arr, int len);
    void print();
    void read_offile();
    void read_file(string file_name);
    void read_console();
    void read();
    void write_infile();
    void write();
    bool all_fine(string line);
    bool* booler(string line, int len);
    void con();
    void bool_to_str();
    void nulling(); 
};
