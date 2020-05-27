#include <iostream>
#include "cosmetico.h"


int main() {
  Cosmetico c(1, "NomeProdotto", "DescrizioneProdotto", 10.50, UOMO, "ApplicazioneCosmetico");
  std::cout << c.mostraProdotto() <<std::endl;
  return 0;
}
