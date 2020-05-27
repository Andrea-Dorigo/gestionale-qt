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


Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Target target, std::string applicazione) :
Prodotto(id, nome, descrizione, prezzo),
_target(target),
_applicazione(applicazione) {}
Cosmetico::~Cosmetico() {}

Cosmetico* Cosmetico::clone() const {
  return new Cosmetico(*this);
}

double Cosmetico::calcoloPrezzo() const {
  return 0.0;
}

std::string Cosmetico::mostraProdotto() const{
  // return "{ \"prodotto\" : [\n   {\"nome\": \"" + getNome() + "\"},\n]}";
  std::string s = "{ \"prodotto\" : [\n   {\"id\": \"" + attributeToString(getId()) + "\"},\n   {\"nome\": \"" + attributeToString(getNome()) + "\"},\n   {\"descrizione\": \"" + attributeToString(getDescrizione()) + "\"},\n   {\"prezzo\": \"" + attributeToString(getPrezzo()) + "\"},\n   {\"target\": \"" + attributeToString(_target) + "\"},\n   {\"Applicazione\": \"" + attributeToString(_applicazione) + "\"},\n]}";
  return s;
}
