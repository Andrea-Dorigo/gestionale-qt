#include <string>
#include <sstream>
//#include <map>
#include "cosmetico.h"

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, Target target, std::string applicazione)
  : Prodotto(id, nome, descrizione, costo, ditta)
  , _target(target)
  , _applicazione(applicazione)
  {}

Cosmetico* Cosmetico::clone() const {
  return new Cosmetico(*this);
}

double Cosmetico::calcoloPrezzo() const {
  return 0.0;
}

// Cosmetico& Cosmetico::operator*() const{
//   return *_target;
// }

// // da spostare in classe serializzazione
// std::string Cosmetico::mostraProdotto() const {
//   std::stringstream ss;
//   ss << Prodotto::mostraProdotto() << "   {\"target\": \"" << targetToString(_target) << "\"},\n   {\"applicazione\": \"" << _applicazione << "\"},\n]}";
//   return ss.str();
// }

// std::string targetToString(Target target) const {
//   return TargetMapForward[target];
// }

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
