#include "vivanda.h"

Vivanda::Vivanda(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza, std::string sapore)
  : Alimentare(id, nome, descrizione, costo, ditta, scadenza)
  , _sapore(sapore)
  {}

bool Vivanda::operator==(const Prodotto& p) const {
  auto aux = dynamic_cast<const Vivanda*>(&p);
  return aux
      && Alimentare::operator==(p)
      && _sapore == aux->getSapore();
}

Vivanda* Vivanda::clone() const {
  return new Vivanda(*this);
}

double Vivanda::calcoloPrezzo() const {
  return 0.0;
}

/* getters */
std::string Vivanda::getSapore() const {
  return _sapore;
}

/* setters */
void Vivanda::setSapore(std::string sapore) {
  _sapore = sapore;
}
