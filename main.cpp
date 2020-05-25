#include <iostream>
#include "cosmetico.cpp"

// using std::string;
// using std::cout;



int main() {
  Cosmetico c(001, "NomeProdotto", "DescrizioneProdotto", 10.50, Uomo, "ApplicazioneCosmetico");
  std::cout << c.Cosmetico::mostraProdotto() << std::endl;
  return 0;
}
