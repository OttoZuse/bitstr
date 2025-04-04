#include <fstream>
#include <iostream>
#include <string>
#include "bitstr.h"
using namespace std;

BitStr::BitStr(string str) {
  binstr.str = booler(str, str.length());
  binstr.line = str;
  binstr.len = str.length();
}
BitStr::BitStr() {}
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
    binstr.line = tmp;
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
void BitStr::print() {
  cout << binstr.line << endl;
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
string BitStr::get_line(){
  return binstr.line;
}
void BitStr::write_infile(string file_name) {
  ofstream out(file_name);
  out << binstr.line << endl;
}
void BitStr::write_console(){
  cout << binstr.line << endl;
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
void BitStr::operator=(BitStr* Bit2){
  if (Bit2 -> get_str()) {
    binstr.str = Bit2 -> get_str();
    binstr.line = Bit2 -> get_line();
    binstr.len = Bit2 -> get_len();
  }
}
BitStr BitStr::operator*(BitStr Bit){
  bool* str = new bool[binstr.len];
  bool* str2 = Bit.get_str();
  for (int i = 0; i < binstr.len; i++)
    str[i] = binstr.str[i] * str2[i];
  binstr.str = str;
  binstr.line = bool_to_str(str, binstr.len);
  return *this;
}
bool* BitStr::get_str(){
  bool* str = new bool[binstr.len];
  for (int i = 0; i < binstr.len; i++)
    str[i] = binstr.str[i];
  return str;
}
