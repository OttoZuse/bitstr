#include <clocale>
#include "bitstr.h"
#include <iostream>
using namespace std;

int main () {
  setlocale(LC_ALL, "Russian");
  BitStr Bit1("11011011");
  BitStr Bit2("1010111111");
  BitStr Bit3("1011110111111");
  BitStr Bita("0111");
  BitStr Bitb("0011");
  Bit1.nulling(Bit2.get_len());
  Bit1.nulling(Bit3.get_len());
  Bit1 & (Bit2 & Bit3);
  Bit1.write_console();
  if (Bita == Bitb)
    std::cout << "== is work" << endl;
  if (Bita < Bitb)
    cout << "A < B" << endl;
  else if (Bita > Bitb)
    cout << "A > B" << endl;
  else
    cout << "No" << endl;
  Bit2.nulling(Bit3.get_len());
  Bit2 & Bit3;
  return 0;
}
