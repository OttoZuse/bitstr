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
    int length(string line);
  public:
    BitStr(string file_read);
    BitStr(const BitStr &Bit2);
    BitStr();
    // ~BitStr();
    void read_file(string file_name, int num_str);
    void read_console();
    void read();
    void readdr(bool* str);
    void write_infile(string file_name);
    void write_console();
    void print_addr();
    void delete_str();
    bool* booler(string line);
    int get_len();
    BitStr operator&(const BitStr& Bit2);
    void operator=(const BitStr& Bit2);
    bool operator==(BitStr Bit2);
    bool operator!=(BitStr Bit2);
    bool operator<(BitStr Bit2);
    bool operator>(BitStr Bit2);
    void nulling(int secondLen);
};
