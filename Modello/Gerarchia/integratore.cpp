#include "integratore.h"

Integratore::Integratore(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, bool dispositivoMedico)
    : Prodotto(id, nome, descrizione, costo, ditta, iva)
    , Alimentare(id, nome, descrizione, costo, ditta, iva, scadenza)
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
    if(_dispositivoMedico) return getCosto() * 2.5 * 0.7;
    else return getCosto() * 2.5;
}

std::string Integratore::stampa() const {
    std::stringstream ss;
    ss << Alimentare::stampa();
    ss << "Dispositivo medico: " << _dispositivoMedico << "\n";
    return ss.str();
}

void Integratore::serialize(QXmlStreamWriter& stream) const {
    Alimentare::serialize(stream);
    stream.writeTextElement("dispositivoMedico", QString::number(Integratore::getDispositivoMedico()));
}

/* getters */
bool Integratore::getDispositivoMedico() const {
    return _dispositivoMedico;
}
std::string Integratore::getTipo() const {
    return "Integratore";
}

/* setters */
void Integratore::setDispositivoMedico(bool dispositivoMedico) {
    _dispositivoMedico = dispositivoMedico;
}
