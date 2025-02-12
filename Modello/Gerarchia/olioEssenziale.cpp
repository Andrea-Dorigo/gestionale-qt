#include "olioEssenziale.h"

OlioEssenziale::OlioEssenziale(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, std::string sapore, Target target, std::string applicazione, std::string profumazione)
    : Prodotto::Prodotto(id, nome, descrizione, costo, ditta, iva)
    , Cosmetico::Cosmetico(id, nome, descrizione, costo, ditta, iva, target, applicazione)
    , Vivanda::Vivanda(id, nome, descrizione, costo, ditta, iva, scadenza, sapore)
    , _profumazione(profumazione)
{}

OlioEssenziale::OlioEssenziale(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, std::string sapore, std::string target, std::string applicazione, std::string profumazione)
    : Prodotto::Prodotto(id, nome, descrizione, costo, ditta, iva)
    , Cosmetico::Cosmetico(id, nome, descrizione, costo, ditta, iva, target, applicazione)
    , Vivanda::Vivanda(id, nome, descrizione, costo, ditta, iva, scadenza, sapore)
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
    ss << Cosmetico::stampa();
    ss << Vivanda::stampa();
    ss << "Profumazione: " << _profumazione << "\n";
    return ss.str();
}

void OlioEssenziale::serialize(QXmlStreamWriter& stream) const {
    Cosmetico::serialize(stream);
    Vivanda::serialize(stream);
    stream.writeTextElement("profumazione", QString::fromStdString(OlioEssenziale::getProfumazione()));
}

/* getters */
std::string OlioEssenziale::getProfumazione() const {
    return _profumazione;
}
std::string OlioEssenziale::getTipo() const {
    return "Olio essenziale";
}

/* setters */
void OlioEssenziale::setProfumazione(std::string profumazione) {
    _profumazione = profumazione;
}
