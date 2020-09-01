#include "cosmetico.h"

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, Target target, std::string applicazione)
  : Prodotto(id, nome, descrizione, costo, ditta, iva)
  , _target(target)
  , _applicazione(applicazione)
  {}

bool Cosmetico::operator==(const Prodotto& p) const {
  auto aux = dynamic_cast<const Cosmetico*>(&p);
  return aux
      && Prodotto::operator==(p)
      && _target == aux->getTarget()
      && _applicazione == aux->getApplicazione();
}

Cosmetico* Cosmetico::clone() const {
  return new Cosmetico(*this);
}

double Cosmetico::calcoloPrezzo() const {
  if(getCosto() > 10 && _target == DONNA) {
    return getCosto()*2 - 5.0;
  }
  else return getCosto()*2;
}

std::string Cosmetico::stampa() const {
  std::stringstream ss;
  ss << Prodotto::stampa();
  ss << "Target: " << _target << "\n";
  ss << "Applicazione: " << _applicazione << "\n";
  return ss.str();
}

/* getters */
Target Cosmetico::getTarget() const {
  return _target;
}

std::string Cosmetico::getApplicazione() const {
  return _applicazione;
}
std::string Cosmetico::getTipo() const {
  return "Cosmetico";
}

/* setters */
void Cosmetico::setTarget(Target target) {
  _target = target;
}
void Cosmetico::setApplicazione(std::string applicazione) {
  _applicazione = applicazione;
}


std::string Cosmetico::targetToString() const {
    switch (_target) {
    case UOMO:
            return "Uomo";
        break;
    case DONNA:
            return "Donna";
        break;
    case UNISEX:
            return "Unisex";
        break;
    default:
            return "Nessun target";
        break;
    }
}
