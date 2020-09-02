#include "vivanda.h"

Vivanda::Vivanda(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, std::string sapore)
    : Prodotto::Prodotto(id, nome, descrizione, costo, ditta, iva)
    , Alimentare::Alimentare(id, nome, descrizione, costo, ditta, iva, scadenza)
    , _sapore(sapore)
{}

bool Vivanda::operator==(const Prodotto& p) const {
    auto aux = dynamic_cast<const Vivanda*>(&p);
    return aux
            && Alimentare::operator==(p)
            && _sapore == aux->getSapore();
}

Vivanda* Vivanda::clone() const {
    return new Vivanda(*this);
}

double Vivanda::calcoloPrezzo() const {
    return getCosto() * 1.8;
}

std::string Vivanda::stampa() const {
    std::stringstream ss;
    ss << Alimentare::stampa();
    ss << "Sapore: " << _sapore << "\n";
    return ss.str();
}

void Vivanda::serialize(QXmlStreamWriter& stream) const {
    Alimentare::serialize(stream);
    stream.writeTextElement("Target", QString::fromStdString(Vivanda::getSapore()));
}

/* getters */
std::string Vivanda::getSapore() const {
    return _sapore;
}
std::string Vivanda::getTipo() const {
    return "Vivanda";
}

/* setters */
void Vivanda::setSapore(std::string sapore) {
    _sapore = sapore;
}
