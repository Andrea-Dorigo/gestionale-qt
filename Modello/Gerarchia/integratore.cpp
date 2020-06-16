#include <string>
#include <sstream>
//#include <map>
#include "integratore.h"

Integratore::Integratore(unsigned short id, std::string nome, std::string descrizione, double prezzo, std::string scadenza, bool dispositivoMedico)
  : Alimentare(id, nome, descrizione, prezzo, scadenza)
  , _dispositivoMedico(dispositivoMedico)
  {}

Integratore* Integratore::clone() const {
  return new Integratore(*this);
}

double Integratore::calcoloPrezzo() const {
  return 0.0;
}

// Integratore& Integratore::operator*() const{
//   return *_target;
// }

// // da spostare in classe serializzazione
// std::string Integratore::mostraProdotto() const {
//   std::stringstream ss;
//   ss << Prodotto::mostraProdotto() << "   {\"target\": \"" << targetToString(_target) << "\"},\n   {\"applicazione\": \"" << _applicazione << "\"},\n]}";
//   return ss.str();
// }

// std::string targetToString(Target target) const {
//   return TargetMapForward[target];
// }

/* getters */
bool Integratore::getDispositivoMedico() const {
  return _dispositivoMedico;
}

/* setters */
void Integratore::setDispositivoMedico(bool dispositivoMedico) {
  _dispositivoMedico = dispositivoMedico;
}
