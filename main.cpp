#include <iostream>
#include "cosmetico.h"

int main() {
  Cosmetico c(001, "NomeProdotto", "DescrizioneProdotto", 10.50, Uomo, "ApplicazioneCosmetico");
  std::cout << c.Cosmetico::mostraProdotto() << std::endl;
  return 0;
}
