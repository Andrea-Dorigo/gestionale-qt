#include <iostream>
#include "cosmetico.h"

int main() {
  Cosmetico c(001, "NomeProdotto", "DescrizioneProdotto", 10.50, Uomo, "ApplicazioneCosmetico");
  std::cout << c.mostraProdotto() << std::endl;
  return 0;
}
