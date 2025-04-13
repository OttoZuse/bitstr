#pragma once
#include <string>
#include <fstream>
using namespace std;

struct binString {
  bool* str;
  int len;
};

class BitStr {
  private:
    binString binstr;
    int step(int a, int b);
    int str_to_dec(bool* boolstr);
    bool all_fine(string line);
    string bool_to_str(bool* arr, int len);
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
    void print_addr();
    bool* booler(string line, int len);
    bool* get_str();
    int get_len();
    BitStr operator&(BitStr Bit2);
    BitStr& operator=(const BitStr& Bit2);
    bool operator==(BitStr Bit2);
    bool operator<(BitStr Bit2);
    bool operator>(BitStr Bit2);
    void nulling(int secondLen);
};
