#include <clocale>
#include "bitstr.h"
#include <iostream>
using namespace std;

int main () {
  setlocale(LC_ALL, "Russian");
  BitStr Bit1("11010111");
  BitStr Bit2("0110111001");
  BitStr Bit3("1011010101111");
  BitStr Bit4 = Bit3;
  // Bit4 = Bit3;
  Bit1.write_console();
  Bit2.write_console();
  // Bit3.write_console();
  // Bit4.write_console();
  Bit1 = Bit1 & Bit2;
  Bit1.write_console();

  // BitStr Bita("0111");
  // BitStr Bitb("0011");
  // Bita.write_console();
  // Bitb.write_console();
  // if (Bita != Bitb)
  //   std::cout << "!= is work" << endl;
  // if (Bita < Bitb)
  //   cout << "A < B" << endl;
  // else if (Bita > Bitb)
  //   cout << "A > B" << endl;
  // else
  //   cout << "No" << endl;
  return 0;
}
