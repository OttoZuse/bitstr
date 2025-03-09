#include <iostream>
#include <fstream>
using namespace std;

void print(bool* arr, int len) {
  for (int i = 0; i < len; i++)
    cout << arr[i];
  cout << endl;
}

bool all_fine(string line) {
  for (char i : line){
    if (i != '0' and i != '1')
      return false;
  }
  return true;
}

bool* input(string line, int len){
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

bool* con(bool* arr1, bool* arr2, int len) {
  bool* arr_con = new bool[len];
  for (int i = 0; i < len; i++)
    arr_con[i] = arr1[i] * arr2[i];
  return arr_con;
}

string bool_to_str(bool* arr, int len) {
  string line;
  for (int i = 0; i < len; i++)
    if (arr[i] == 1)
      line += '1';
    else
      line += '0';
  return line;
}

void nulling(int max, int min, bool* arr) {
  bool* arr_tmp = new bool[max];
  for (int i = 0; i < min; i++)
    arr_tmp[i] = arr[i];
  for (int i = min; i < max; i++)
    arr_tmp[i] = 0;
  arr = arr_tmp;
}

int main() {
  setlocale(LC_ALL, "Russian");
  ofstream out("string_output", ios::app);
  ifstream in("string_input");

  string tmp1 = "";
  string tmp2 = "";
  bool* arr1;
  bool* arr2;
  bool* arr_con;
  string line;
  char type_read;
  char type_write;
  int len1, len2;
  while (type_read != '1' and type_read != '2') {
    cout << "[1]Читать из файла/[2]Читать из консоли?" << endl;
    cin >> type_read;
  }
  if (type_read == '1') {
    getline(in, tmp1);
    getline(in, tmp2);
  }
  else if (type_read == '0') {
    cin >> tmp1;
    cin >> tmp2;
  }
  if (!all_fine(tmp1) or !all_fine(tmp2)) {
    cout << "Неверный тип" << endl;
    return 0;
  }
  len1 = tmp1.length();
  len2 = tmp2.length();
  arr1 = input(tmp1, len1);
  arr2 = input(tmp2, len2);
  int max;
  if (len1 > len2) {
    nulling(len1, len2, arr1);
    max = len1;
  }
  else if (len1 < len2) {
    nulling(len2, len1, arr2);
    max = len2;
  }

  while (type_write != '1' and type_write != '2') {
    cout << "[1]Записывать в файл/[2]Вывод в консоль?" << endl;
    cin >> type_write;
  }
  if (type_write == '2')
    print(con(arr1, arr2, max), max);

  else if (type_write == '1')
    out << bool_to_str(con(arr1, arr2, max), max) << endl; 
  

  return 0;
}
