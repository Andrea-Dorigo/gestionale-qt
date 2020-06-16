#include <string>
#include <sstream>
//#include <map>
#include "vivanda.h"

Vivanda::Vivanda(unsigned short id, std::string nome, std::string descrizione, double prezzo, std::string scadenza, std::string sapore)
  : Alimentare(id, nome, descrizione, prezzo, scadenza)
  , _sapore(sapore)
  {}

Vivanda* Vivanda::clone() const {
  return new Vivanda(*this);
}

double Vivanda::calcoloPrezzo() const {
  return 0.0;
}

// Vivanda& Vivanda::operator*() const{
//   return *_target;
// }

// // da spostare in classe serializzazione
// std::string Vivanda::mostraProdotto() const {
//   std::stringstream ss;
//   ss << Prodotto::mostraProdotto() << "   {\"target\": \"" << targetToString(_target) << "\"},\n   {\"applicazione\": \"" << _applicazione << "\"},\n]}";
//   return ss.str();
// }

// std::string targetToString(Target target) const {
//   return TargetMapForward[target];
// }

/* getters */
std::string Vivanda::getSapore() const {
  return _sapore;
}

/* setters */
void Vivanda::setSapore(std::string sapore) {
  _sapore = sapore;
}
