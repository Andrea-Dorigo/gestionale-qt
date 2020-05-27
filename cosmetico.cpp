#include "cosmetico.h"

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Target target, std::string applicazione) :
Prodotto(id, nome, descrizione, prezzo),
_target(target),
_applicazione(applicazione) {}

Cosmetico* Cosmetico::clone() const {
  return new Cosmetico(*this);
}

double Cosmetico::calcoloPrezzo() const {
  return calcoloPrezzo();
}

std::string Cosmetico::mostraProdotto() const{
  return _applicazione;
}

Cosmetico::~Cosmetico() {}
