#include <string>
#include <sstream>
//#include <map>
#include "olioEssenziale.h"

OlioEssenziale::OlioEssenziale(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza, std::string sapore, Target target, std::string applicazione, std::string profumazione)
  : Vivanda(id, nome, descrizione, costo, ditta, scadenza, sapore)
  , Cosmetico(id, nome, descrizione, costo, ditta, target, applicazione)
  , _profumazione(profumazione)
  {}

bool OlioEssenziale::operator==(const Prodotto& p) const {
  auto aux = dynamic_cast<const OlioEssenziale*>(&p);
  return aux
      && Cosmetico::operator==(p)
      && Vivanda::operator==(p)
      && _profumazione == aux->getProfumazione();
}

OlioEssenziale* OlioEssenziale::clone() const {
  return new OlioEssenziale(*this);
}

double OlioEssenziale::calcoloPrezzo() const {
  return 0.0;
}

// OlioEssenziale& OlioEssenziale::operator*() const{
//   return *_target;
// }

// // da spostare in classe serializzazione
// std::string OlioEssenziale::mostraProdotto() const {
//   std::stringstream ss;
//   ss << Prodotto::mostraProdotto() << "   {\"target\": \"" << targetToString(_target) << "\"},\n   {\"applicazione\": \"" << _applicazione << "\"},\n]}";
//   return ss.str();
// }

// std::string targetToString(Target target) const {
//   return TargetMapForward[target];
// }

/* getters */
std::string OlioEssenziale::getProfumazione() const {
  return _profumazione;
}

/* setters */
void OlioEssenziale::setProfumazione(std::string profumazione) {
  _profumazione = profumazione;
}
