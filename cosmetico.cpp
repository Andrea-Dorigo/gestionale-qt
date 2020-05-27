#include "cosmetico.h"

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Target target, std::string applicazione)
  : Prodotto(id, nome, descrizione, prezzo)
  , _target(target)
  , _applicazione(applicazione)
  {}

Cosmetico::~Cosmetico() {}

Cosmetico* Cosmetico::clone() const {
  return new Cosmetico(*this);
}

double Cosmetico::calcoloPrezzo() const {
  return 0.0;
}

std::string Cosmetico::mostraProdotto() const{
  return "{ \"prodotto\" : [\n   {\"nome\": \"" + getNome() + "\"},\n]}";
}

/* getters */
Target getTarget() const {
  return _target;
}
std::string getApplicazione() const {
  return _applicazione;
}

/* setters */
void setTarget(Target target) {
  _target = target;
}
void setApplicazione(std::string applicazione) {
  _applicazione = applicazione;
}
