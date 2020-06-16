#include "integratore.h"

Integratore::Integratore(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza, bool dispositivoMedico)
  : Alimentare(id, nome, descrizione, costo, ditta, scadenza)
  , _dispositivoMedico(dispositivoMedico)
  {}

bool Integratore::operator==(const Prodotto& p) const {
  auto aux = dynamic_cast<const Integratore*>(&p);
  return aux
      && Alimentare::operator==(p)
      && _dispositivoMedico == aux->getDispositivoMedico();
}

Integratore* Integratore::clone() const {
  return new Integratore(*this);
}

double Integratore::calcoloPrezzo() const {
  return 0.0;
}

/* getters */
bool Integratore::getDispositivoMedico() const {
  return _dispositivoMedico;
}

/* setters */
void Integratore::setDispositivoMedico(bool dispositivoMedico) {
  _dispositivoMedico = dispositivoMedico;
}
