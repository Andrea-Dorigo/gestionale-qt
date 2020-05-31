#include <iostream>
// #include <string>
#include "cosmetico.h"
#include "magazzino.h"
// #include "nlohmann/json.hpp"
// #include "serialize.h"

int main() {
  /* costruttori a cui fare riferimento
       Prodotto(unsigned short id, std::string nome, std::string descrizione, double prezzo=0.0);
       Cosmetico(Target target, std::string applicazione);
  */

  Cosmetico c(1, "NomeProdotto", "DescrizioneProdotto", 10.50, UOMO, "ApplicazioneCosmetico");
  Cosmetico* p = &c;
  Magazzino m;
  bool a,b,d;
  std::cout << a << b << d <<std::endl;
  a=m.Magazzino::insert(p);
  b=m.Magazzino::mostraProdotto(p);
  d=m.Magazzino::deleteProdotto(1);
  std::cout << a << b << d <<std::endl;




  // std::cout << c.mostraProdotto() << std::endl;

  //Cosmetico c(1, "nome", "descrizione", 0.5, DONNA, "applicazione");
  //nlohmann::json documento; //non funziona anche se dovrebbe
  //c.to_json(documento, c);
  //std::cout << documento << std::endl;


  return 0;
}
