#include <iostream>
#include "cosmetico.cpp"

// using std::string;
// using std::cout;



int main() {
  Cosmetico c(Uomo,"schiaffarselo in faccia");
  std::cout << c.Cosmetico::mostraProdotto() << std::endl;
  return 0;
}
