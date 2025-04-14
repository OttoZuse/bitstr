#include <cmath>
#include <fstream>
#include <iostream>
#include <string>
#include "bitstr.h"
using namespace std;

BitStr::BitStr(string str) {
  binstr.str = booler(str, str.length());
  binstr.len = str.length();
}
BitStr::BitStr() {}
// 
// BitStr::~BitStr() {
//   delete[] binstr.str;
// }
void BitStr::read_file(string file_name) {
  string tmp;
  ifstream in(file_name);
  getline(in, tmp);
  if (!all_fine(tmp))
    cout << "Ошибка типизации" << endl;
  else {
    binstr.str = booler(tmp, tmp.length());
  }
}
void BitStr::read_console() {
  string tmp;
  cin >> tmp;
  if (!all_fine(tmp))
    cout << "Ошибка типизации" << endl;
  else {
    binstr.len = tmp.length();
    binstr.str = booler(tmp, binstr.len);
  }
}
bool* BitStr::booler(string line, int len) {
  bool* arr = new bool[len];
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
  for (char i : line){
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
  out << bool_to_str(binstr.str, binstr.len) << endl;
}
void BitStr::write_console(){
  cout << bool_to_str(binstr.str, binstr.len)<< endl;
}
void BitStr::nulling(int secondLen){
  if (secondLen > binstr.len) {
    int maxlen = secondLen;
    bool* arr_tmp = new bool[maxlen];
    for (int i = 0; i < binstr.len; i++)
      arr_tmp[i] = binstr.str[i];
    for (int i = binstr.len; i < maxlen; i++)
      arr_tmp[i] = 0;
    delete[] binstr.str;
    binstr.len = maxlen;
    binstr.str = arr_tmp;
  }
}
int BitStr::get_len(){
  return binstr.len;
}
int BitStr::str_to_dec(bool* boolstr) {
  int result = 0;
  for (int i = binstr.len - 1; i >= 0; i--) {
    result += boolstr[i] * step(2, binstr.len - i - 1);
  }
  return result;
}
int BitStr::step(int a, int b) {
  int result = 1;
  for (int i = 1; i <= b; i++)
    result *= a;
  return result;
}
void BitStr::operator=(const BitStr& Bit2){
  // if (binstr.str != nullptr)
  //   delete[] binstr.str;
  if (this != &Bit2) {
    binstr.len = Bit2.binstr.len;
    binstr.str = new bool[binstr.len];
    copy(Bit2.binstr.str, Bit2.binstr.str + binstr.len, binstr.str);
  }
}
bool BitStr::operator<(BitStr Bit2) {
  int dec1 = str_to_dec(binstr.str);
  int dec2 = str_to_dec(Bit2.binstr.str);
  if (dec1 < dec2)
    return true;
  else
    return false;
}
bool BitStr::operator>(BitStr Bit2) {
  int dec1 = str_to_dec(binstr.str);
  int dec2 = str_to_dec(Bit2.binstr.str);
  if (dec1 > dec2)
    return true;
  else
    return false;
}
bool BitStr::operator==(BitStr Bit2) {
  for (int i = 0; i < binstr.len; i++)
    if (binstr.str[i] != Bit2.binstr.str[i])
      return false;
  return true;
}
BitStr& BitStr::operator&(const BitStr& Bit) {
  if (binstr.len != Bit.binstr.len)
    nulling(Bit.binstr.len);
  bool* str = new bool[binstr.len];
  for (int i = 0; i < binstr.len; i++)
    str[i] = binstr.str[i] * Bit.binstr.str[i];
  delete[] binstr.str;
  binstr.str = str;
  return *this;
}
void BitStr::print_addr(){
  cout << binstr.str << endl;
}
