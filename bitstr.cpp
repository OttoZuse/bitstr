#include <clocale>
#include "bitstr.h"
using namespace std;

int main () {
  setlocale(LC_ALL, "Russian");
  BitStr Bit("string_input", "string_output");
  Bit.read();
  Bit.nulling();
  Bit.con();
  Bit.write();

  return 0;
}
