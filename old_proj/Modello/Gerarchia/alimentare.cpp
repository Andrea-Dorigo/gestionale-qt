#include "alimentare.h"

Alimentare::Alimentare(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza)
  : Prodotto(id, nome, descrizione, costo, ditta, iva)
  , _scadenza(scadenza)
  {}

bool Alimentare::operator==(const Prodotto& p) const {
  auto aux = dynamic_cast<const Alimentare*>(&p);
  return aux
      && Prodotto::operator==(p)
      && _scadenza == aux->getScadenza();
}

std::string Alimentare::stampa() const {
  std::stringstream ss;
  ss << Prodotto::stampa();
  ss << "Scadenza: " << _scadenza << "\n";
  return ss.str();
}

/* getters */
std::string Alimentare::getScadenza() const {
  return _scadenza;
}

/* setters */
void Alimentare::setScadenza(std::string scadenza) {
  _scadenza = scadenza;
}
