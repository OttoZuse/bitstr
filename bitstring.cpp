#include <fstream>
#include <iostream>
#include <string>
#include "bitstr.h"
using namespace std;

BitStr::BitStr(string str) {
  if (all_fine(str)) {
    binstr.str = booler(str);
    binstr.len = str.length();
  }
  else {
    binstr.str = nullptr;
    binstr.len = 0;
  }
}
BitStr::BitStr(const BitStr &Bit2) {
  if (this != &Bit2 and Bit2.binstr.str != nullptr) {
    binstr.len = Bit2.binstr.len;
    binstr.str = new bool[binstr.len];
    copy(Bit2.binstr.str, Bit2.binstr.str + binstr.len, binstr.str);
  }
  else {
    binstr.str = nullptr;
    binstr.len = 0;
  }
}
void BitStr::delete_str() {
  delete [] binstr.str;
  binstr.str = nullptr;
  binstr.len = 0;
}
void BitStr::operator=(const BitStr& Bit2){
  if (binstr.str != nullptr)
    delete[] binstr.str;
  if (this != &Bit2 and Bit2.binstr.str != nullptr) {
    binstr.len = Bit2.binstr.len;
    binstr.str = new bool[binstr.len];
    copy(Bit2.binstr.str, Bit2.binstr.str + binstr.len, binstr.str);
  }
}
BitStr::BitStr() { binstr.str = nullptr; binstr.len = 0; }
// BitStr::~BitStr() {
//   delete[] binstr.str;
// }
int BitStr::length(string line){
  int count = 0;
  for (char i : line)
    count++;
  return count;
}
void BitStr::read_file(string file_name, int num_str) {
  num_str--;
  string tmp;
  ifstream in(file_name);
  if (in) {
    int index = -1;
    do {
        index++;
        getline(in, tmp);
    } while (index != num_str and !in.eof());
    if (!all_fine(tmp)) {
      cout << "Ошибка типизации" << endl;
    }
    else {
      if (binstr.str != nullptr)
        delete [] binstr.str;
      binstr.len = length(tmp);
      binstr.str = booler(tmp);
    }
  }
  else
    cout << "Файл " << file_name << " не найден" << endl;
}
void BitStr::read_console() {
  string tmp;
  cin >> tmp;
  if (!all_fine(tmp))
    cout << "Ошибка типизации" << endl;
  else {
    binstr.len = length(tmp);
    binstr.str = booler(tmp);
  }
}
bool* BitStr::booler(string line) {
  bool* arr = new bool[length(line)];
  int count = 0;
  for (char i : line) {
    if (i == '1')
      arr[count] = 1;
    else
      arr[count] = 0;
    count++;
  }
  return arr;
}
bool BitStr::all_fine(string line) {
  for (char i : line) {
    if (i != '0' and i != '1') 
      return false;
  }
  return true;
}
string BitStr::bool_to_str(bool* arr, int len) {
  string line;
  for (int i = 0; i < len; i++)
    if (arr[i] == 1)
      line += '1';
    else
      line += '0';
  return line;
}
void BitStr::write_infile(string file_name) {
  ofstream out(file_name);
  if (binstr.str != nullptr)
    out << bool_to_str(binstr.str, binstr.len) << endl;
  else
    out << "empty" << endl;
}
void BitStr::write_console(){
  if (binstr.str != nullptr)
    cout << bool_to_str(binstr.str, binstr.len) << endl;
  else
    cout << "empty" << endl;
}
void BitStr::nulling(int secondLen){
  if (secondLen > binstr.len and binstr.str != nullptr) {
    bool* arr_tmp = new bool[secondLen];
    for (int i = 0; i < binstr.len; i++)
      arr_tmp[i] = binstr.str[i];
    for (int i = binstr.len; i < secondLen; i++)
      arr_tmp[i] = 0;
    delete[] binstr.str;
    binstr.len = secondLen;
    binstr.str = arr_tmp;
  }
}
int BitStr::get_len(){
  return binstr.len;
}
int BitStr::str_to_dec(bool* boolstr) {
  if (boolstr != nullptr) {
    int result = 0;
    for (int i = binstr.len - 1; i >= 0; i--) {
      result += boolstr[i] * step(2, binstr.len - i - 1);
    }
    return result;
  }
  return -1;
}
int BitStr::step(int a, int b) {
  int result = 1;
  for (int i = 1; i <= b; i++)
    result *= a;
  return result;
}
bool BitStr::operator<(BitStr Bit2) {
  int dec1 = str_to_dec(binstr.str);
  int dec2 = str_to_dec(Bit2.binstr.str);
  if (dec1 == -1 or dec2 == -1) {
    cout << "Строка не определена" << endl;
    exit(0);
  }
  else if (dec1 < dec2)
    return true;
  return false;
}
bool BitStr::operator>(BitStr Bit2) {
  int dec1 = str_to_dec(binstr.str);
  int dec2 = str_to_dec(Bit2.binstr.str);
  if (dec1 == -1 or dec2 == -1) {
    cout << "Строка не определена" << endl;
    exit(0);
  }
  else if (dec1 > dec2)
    return true;
  return false;
}
bool BitStr::operator==(BitStr Bit2) {
  if (binstr.str == Bit2.binstr.str)
    return true;
  if (binstr.str == nullptr xor Bit2.binstr.str == nullptr)
    return false;
  if (binstr.len != Bit2.binstr.len)
    return false;
  for (int i = 0; i < binstr.len; i++)
    if (binstr.str[i] != Bit2.binstr.str[i])
      return false;
  return true;
}
bool BitStr::operator!=(BitStr Bit2) {
  if (binstr.str == Bit2.binstr.str or binstr.len != Bit2.binstr.len)
    return true;
  if (binstr.str == nullptr xor Bit2.binstr.str == nullptr)
    return true;
  if (str_to_dec(binstr.str) == str_to_dec(Bit2.binstr.str))
    return false;
  return true;
}
void BitStr::readdr(bool* str) {
  if (binstr.str != nullptr)
    delete[] binstr.str;
  binstr.str = new bool[binstr.len];
  copy(str, str + binstr.len, binstr.str);
}
BitStr BitStr::operator&(const BitStr& Bit) {
  if (binstr.str != nullptr and Bit.binstr.str != nullptr) {
    BitStr new_Bit(*this);
    new_Bit.nulling(Bit.binstr.len);
    bool* str = new bool[new_Bit.binstr.len];
    for (int i = 0; i < new_Bit.binstr.len; i++)
      str[i] = new_Bit.binstr.str[i] * Bit.binstr.str[i];
    new_Bit.readdr(str);
    delete[] str;
    return new_Bit;
  }
  return *this;
}
void BitStr::print_addr(){
  cout << binstr.str << endl;
}
