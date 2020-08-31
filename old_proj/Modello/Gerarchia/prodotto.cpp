#include "prodotto.h"

Prodotto::Prodotto(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva)
  : _id(id)
  , _nome(nome)
  , _descrizione(descrizione)
  , _costo(costo)
  , _ditta(ditta)
  , _iva(iva)
  {}

Prodotto::~Prodotto() = default;

bool Prodotto::operator==(const Prodotto& p) const {
  return _id == p.getId()
      && _nome == p.getNome()
      && _descrizione == p.getDescrizione()
      && _costo == p.getCosto()
      && _ditta == p.getDitta();
}

std::string Prodotto::stampa() const {
  std::stringstream ss;
  ss << "ID: " << _id << "\n";
  ss << "Nome: " << _nome << "\n";
  ss << "Ditta: " << _ditta << "\n";
  ss << "Descrizione: " << _descrizione << "\n";
  ss << "Costo: " << _costo << "\n";
  ss << "IVA " << _iva << "\n";
  return ss.str();
}

/* getters */
unsigned short Prodotto::getId() const {
  return _id;
}
std::string Prodotto::getNome() const {
  return _nome;
}
std::string Prodotto::getDescrizione() const {
  return _descrizione;
}
double Prodotto::getCosto() const {
  return _costo;
}
std::string Prodotto::getDitta() const {
  return _ditta;
}
int Prodotto::getIva() const {
  return _iva;
}

/* setters */
void Prodotto::setId(unsigned short id) {
  _id = id;
}
void Prodotto::setNome(std::string nome) {
  _nome = nome;
}
void Prodotto::setDescrizione(std::string descrizione) {
  _descrizione = descrizione;
}
void Prodotto::setCosto(double costo) {
  _costo = costo;
}
void Prodotto::setDitta(std::string ditta) {
  _ditta = ditta;
}
void Prodotto::setIva(int iva) {
  _iva = iva;
}
