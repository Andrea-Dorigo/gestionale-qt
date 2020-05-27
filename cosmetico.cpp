#include "cosmetico.h"

template <>
std::string attributeToString(Target t){
  std::string s;
  switch (t) {
    case UOMO:
      s="Uomo";
      break;
    case DONNA:
      s="Donna";
      break;
    case UNISEX:
      s="Unisex";
      break;
  }
  return s;
}

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

std::string Cosmetico::mostraProdotto() const {
  std::string s = Prodotto::mostraProdotto() + "   {\"target\": \"" + attributeToString(_target) + "\"},\n   {\"applicazione\": \"" + attributeToString(_applicazione) + "\"},\n]}";
  return s;
}

/* getters */
Target Cosmetico::getTarget() const {
  return _target;
}
std::string Cosmetico::getApplicazione() const {
  return _applicazione;
}

/* setters */
void Cosmetico::setTarget(Target target) {
  _target = target;
}
void Cosmetico::setApplicazione(std::string applicazione) {
  _applicazione = applicazione;
}
