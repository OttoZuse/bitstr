#include <clocale>
#include "bitstr.h"
#include <iostream>
using namespace std;

int main () {
  setlocale(LC_ALL, "Russian");
  BitStr Bit1("01011011");
  BitStr Bit2("1010111111");
  BitStr Bit3("1011010101111");
  BitStr Bit4;
  Bit4 = Bit3;
  // Bit3.print_addr();
  // Bit4.print_addr();
  Bit1.write_console();
  Bit2.write_console();
  // Bit3.write_console();
  Bit4.write_console();
  // Bit1.nulling(Bit3.get_len());
  // Bit2.nulling(Bit3.get_len());
  Bit1 & Bit2 & Bit4;
  Bit1.write_console();
  // BitStr Bita("0111");
  // BitStr Bitb("0011");
  // Bita.write_console();
  // Bitb.write_console();
  // if (Bita == Bitb)
  //   std::cout << "== is work" << endl;
  // if (Bita < Bitb)
  //   cout << "A < B" << endl;
  // else if (Bita > Bitb)
  //   cout << "A > B" << endl;
  // else
  //   cout << "No" << endl;
  return 0;
}
