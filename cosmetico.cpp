#include <string>
#include <sstream>
//#include "nlohmann/json.hpp"
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

/* da spostare in classe serializzazione */
/*
std::string Cosmetico::mostraProdotto() const {
  std::stringstream ss;
  ss << Prodotto::mostraProdotto() << "   {\"target\": \"" << targetToString(_target) << "\"},\n   {\"applicazione\": \"" << _applicazione << "\"},\n]}";
  return ss.str();
}

template <>
std::string Cosmetico::targetToString(Target t) const {
  std::string s;
  switch (t) {
    case UOMO:
      return "Uomo";
    case DONNA:
      return "Donna";
    case UNISEX:
      return "Unisex";
    default:
      return "";
  }
}

// https://github.com/nlohmann/json#basic-usage
void Cosmetico::to_json(nlohmann::json& j, const Cosmetico& p) {
  j = nlohmann::json{{"Target", p.getTarget()}, {"applicazione", p.getApplicazione()}};
}

std::string targetToString(Target target) const {
  return TargetMapForward[target];
}
*/

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

// Cosmetico& Cosmetico::operator*() const{
//   return *_target;
// }
