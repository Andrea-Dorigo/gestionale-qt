#include "olioEssenziale.h"

OlioEssenziale::OlioEssenziale(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, std::string sapore, Target target, std::string applicazione, std::string profumazione)
  : Vivanda(id, nome, descrizione, costo, ditta, iva, scadenza, sapore)
  , Cosmetico(id, nome, descrizione, costo, ditta, iva, target, applicazione)
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
  return Cosmetico::calcoloPrezzo();
}

std::string OlioEssenziale::stampa() const {
  std::stringstream ss;
  ss << Cosmetico::stampa(); // WARNING: controllare la correttezza
  ss << Vivanda::stampa(); // WARNING: controllare la correttezza
  ss << "Profumazione: " << _profumazione << "\n";
  return ss.str();
}

/* getters */
std::string OlioEssenziale::getProfumazione() const {
  return _profumazione;
}
std::string OlioEssenziale::getTipo() const {
  return "OlioEssenziale";
}

/* setters */
void OlioEssenziale::setProfumazione(std::string profumazione) {
  _profumazione = profumazione;
}
