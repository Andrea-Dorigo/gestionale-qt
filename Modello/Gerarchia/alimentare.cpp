#include <string>
#include <sstream>
//#include <map>
#include "alimentare.h"

Alimentare::Alimentare(unsigned short id, std::string nome, std::string descrizione, double prezzo, std::string scadenza)
  : Prodotto(id, nome, descrizione, prezzo)
  , _scadenza(scadenza)
  {}

/* getters */
std::string Alimentare::getScadenza() const {
  return _scadenza;
}

/* setters */
void Alimentare::setScadenza(std::string scadenza) {
  _scadenza = scadenza;
}
