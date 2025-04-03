#include <fstream>
#include <iostream>
#include <string>
// #include <fstream>
#include "bitstr.h"
using namespace std;

BitStr::BitStr(string str) {
  this -> tmp = str;
}
BitStr::BitStr() {}

// void BitStr::read_offile() {
//   ifstream in(file_read);
//   getline(in, tmp);
// }
// void BitStr::read() {
//   while (type_read != 'f' and type_read != 'c') {
//     cout << "[f]Читать из файла/[c]Читать из консоли ";
//     cin >> type_read;
//   }
//   if (type_read == 'f')
//     read_file(file_read);
//   else
//     read_console();
// }
void BitStr::read_file(string file_name) {
  ifstream in(file_name);
  getline(in, tmp);
  if (!all_fine(tmp))
    cout << "Ошибка типизации" << endl;
  else {
    binstr -> str = booler(tmp, tmp.length());
  }
}
void BitStr::read_console() {
  cin >> tmp;
  if (!all_fine(tmp))
    cout << "Ошибка типизации" << endl;
  else {
    arr = booler(tmp, tmp.length());
  }
}
// char BitStr::get_typer() { return type_read; }
// char BitStr::get_typew() { return type_write; }

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
// void BitStr::print_array(bool* arr, int lent) {
//   for (int i = 0; i < lent; i++)
//     cout << arr[i];
//   cout << endl;
// }
// void BitStr::print() {
//   cout << binstr -> line << endl;
// }
string* BitStr::bool_to_str(bool* arr, int len) {
  string* line;
  for (int i = 0; i < len; i++)
    if (arr[i] == 1)
      line += '1';
    else
      line += '0';
  return line;
}
string BitStr::get_line(){
  return *(binstr -> line);
}
// void BitStr::write_infile() {
//   ofstream out(file_write);
//   out << binstr -> line << endl;
// }
// void BitStr::write() {
//   while (type_write != 'f' and type_write != 'c') {
//     cout << "[f]Записывать в файл/[c]Вывод в консоль? ";
//     cin >> type_write;
//   }
//   if (type_write == 'f')
//     write_infile();
//   else
//     print();
// }
void BitStr::nulling(int secondLen){
  bool* arr_tmp = new bool;
  for (int i = 0; i < binstr -> len; i++)
    arr_tmp[i] = binstr -> str[i];
  for (int i = binstr -> len; i < secondLen; i++)
    arr_tmp[i] = 0;
  binstr -> str = arr_tmp;
}
binString* BitStr::get_binstr(){
  return binstr;
}
void BitStr::operator=(binString* binstr){
  this -> binstr = binstr;
}
binString* BitStr::operator*(BitStr Bit){
  binstr -> str = new bool[binstr -> len];
  for (int i = 0; i < maxlen; i++)
    binstr -> str[i] = binstr -> str[i] * Bit.binstr -> str[i];
  binstr -> line = bool_to_str(binstr -> str, maxlen);
  return binstr;
}

// void BitStr::con() {
//   arr_con = new bool[len];
//   for (int i = 0; i < len; i++)
//     arr_con[i] = arr1[i] * arr2[i];
//   bool_to_str();
// }
