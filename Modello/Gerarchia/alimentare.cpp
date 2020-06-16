#include <string>
#include <sstream>
//#include <map>
#include "alimentare.h"

Alimentare::Alimentare(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza)
  : Prodotto(id, nome, descrizione, costo, ditta)
  , _scadenza(scadenza)
  {}

bool Alimentare::operator==(const Prodotto& p) const {
  auto aux = dynamic_cast<const Alimentare*>(&p);
  return aux
      && Prodotto::operator==(p)
      && _scadenza == aux->getScadenza();
}

/* getters */
std::string Alimentare::getScadenza() const {
  return _scadenza;
}

/* setters */
void Alimentare::setScadenza(std::string scadenza) {
  _scadenza = scadenza;
}
