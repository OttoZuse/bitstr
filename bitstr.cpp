#include <clocale>
#include "bitstr.h"
// #include <iostream>
using namespace std;



int main () {
  setlocale(LC_ALL, "Russian");
  BitStr Bit1("11011011");
  BitStr Bit2("1010111111");
  BitStr Bit3("1011110111111");
  // Bit1.read_console();
  // Bit2.read_console();
  // Bit3.read_console();
  Bit1.nulling(Bit2.get_len());
  Bit1.nulling(Bit3.get_len());
  Bit1 * (Bit2 * Bit3);
  Bit1.write_console();

  return 0;
}
