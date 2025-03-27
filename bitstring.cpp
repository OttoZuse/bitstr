#include <iostream>
#include <fstream>
#include "bitstr.h"
using namespace std;

BitStr::BitStr(string file_read, string file_write) {
  this -> file_read = file_read;
  this -> file_write = file_write;
}
BitStr::BitStr() {}

void BitStr::read_offile() {
  ifstream in(file_read);
  getline(in, tmp1);
  getline(in, tmp2);
}
void BitStr::read() {
  while (type_read != 'f' and type_read != 'c') {
    cout << "[f]Читать из файла/[c]Читать из консоли ";
    cin >> type_read;
  }
  if (type_read == 'f')
    read_file(file_read);
  else
    read_console();
}
void BitStr::read_file(string file_name) {
  file_read = file_name;
  read_offile();
  if (!all_fine(tmp1) or !all_fine(tmp2))
    cout << "Ошибка типизации" << endl;
  else {
    arr1 = booler(tmp1, tmp1.length());
    arr2 = booler(tmp2, tmp2.length());
  }
}
void BitStr::read_console() {
  cin >> tmp1;
  cin >> tmp2;
  if (!all_fine(tmp1) or !all_fine(tmp2))
    cout << "Ошибка типизации" << endl;
  else {
    arr1 = booler(tmp1, tmp1.length());
    arr2 = booler(tmp2, tmp2.length());
  }
}
char BitStr::get_typer() { return type_read; }
char BitStr::get_typew() { return type_write; }

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
void BitStr::print_array(bool* arr, int lent) {
  for (int i = 0; i < lent; i++)
    cout << arr[i];
  cout << endl;
}
void BitStr::print() {
  cout << line << endl;
}
// string BitStr::bool_to_str(bool* arr, int len) {
//   string line;
//   for (int i = 0; i < len; i++)
//     if (arr[i] == 1)
//       line += '1';
//     else
//       line += '0';
//   return line;
// }
void BitStr::bool_to_str() {
  for (int i = 0; i < len; i++)
    if (arr_con[i] == 1)
      line += '1';
    else
      line += '0';
}
void BitStr::write_infile() {
  ofstream out(file_write);
  out << line << endl;
}
void BitStr::write() {
  while (type_write != 'f' and type_write != 'c') {
    cout << "[f]Записывать в файл/[c]Вывод в консоль? ";
    cin >> type_write;
  }
  if (type_write == 'f')
    write_infile();
  else
    print();
}
void BitStr::nulling() {
  int len1 = tmp1.length();
  int len2 = tmp2.length();
  bool* arr;
  if (len1 < len2) {
    min = len1;
    max = len2;
    arr = arr1;
  } else {
    min = len2;
    max = len1;
    arr = arr2;
  }
  arr_tmp = new bool[max];
  for (int i = 0; i < min; i++)
    arr_tmp[i] = arr[i];
  for (int i = min; i < max; i++)
    arr_tmp[i] = 0;
  arr = arr_tmp;

  if (len1 == min)
    arr1 = arr;
  else
    arr2 = arr;
  len = max;
}
void BitStr::con() {
  arr_con = new bool[len];
  for (int i = 0; i < len; i++)
    arr_con[i] = arr1[i] * arr2[i];
  bool_to_str();
}
