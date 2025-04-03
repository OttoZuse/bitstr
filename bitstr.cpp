#include <clocale>
#include "bitstr.h"
using namespace std;



int main () {
  setlocale(LC_ALL, "Russian");
  BitStr Bit1();
  BitStr Bit2();
  Bit1.read_console();
  Bit2.read_console();
  Bit1.nulling(Bit2.get_binstr() -> len);
  Bit1 = Bit1 * Bit2;
  Bit1.write();

  return 0;
}
