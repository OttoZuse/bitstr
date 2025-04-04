#pragma once
#include <string>
#include <fstream>
using namespace std;

struct binString {
  bool* str;
  int len;
  string line;
};

class BitStr {
  private:
    binString binstr;
  public:
    BitStr(string file_read);
    BitStr();
    // ~BitStr();
    void print();
    void read_file(string file_name);
    void read_console();
    void read();
    void write_infile(string file_name);
    void write_console();
    bool all_fine(string line);
    bool* booler(string line, int len);
    string get_line();
    bool* get_str();
    int get_len();
    BitStr operator*(BitStr Bit2);
    void operator=(BitStr* Bit2);
    void nulling(int secondLen); 
    string bool_to_str(bool* arr, int len);
};
