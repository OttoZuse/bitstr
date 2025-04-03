#pragma once
#include <string>
#include <fstream>
using namespace std;

struct binString {
  char* tmpstr;
  bool* str;
  int len;
  string* line;
  // void bool_to_str();
};

class BitStr {
  private:
    binString* binstr;
    bool* arr;
    int maxlen;
    // char type_read;
    // char type_write;
    string tmp;
    string file_read;
    string file_write;
    // string bool_to_str(bool* arr, int len);
  public:
    BitStr(string file_read);
    BitStr();
    // char get_typer();
    // char get_typew();
    // void print_array(bool* arr, int len);
    // void print();
    // void read_offile();
    void read_file(string file_name);
    void read_console();
    void read();
    void write_infile();
    void write();
    bool all_fine(string line);
    bool* booler(string line, int len);
    void con();
    string get_line();
    binString* operator*(BitStr Bit);
    void operator=(binString* binstr);
    void nulling(int secondLen); 
    binString* get_binstr();
    string* bool_to_str(bool* arr, int len);
};
