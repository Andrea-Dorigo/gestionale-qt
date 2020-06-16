#include <string>
#include <sstream>
#include "prodotto.h"

Prodotto::Prodotto(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta)
  : _id(id)
  , _nome(nome)
  , _descrizione(descrizione)
  , _costo(costo)
  , _ditta(ditta)
  {}

Prodotto::~Prodotto() = default;

// // da spostare in classe serializzazione
// std::string Prodotto::mostraProdotto() const {
//   std::stringstream ss;
//   ss << "{ \"prodotto\" : [\n   {\"id\": \"" << _id  << "\"},\n   {\"nome\": \"" << _nome << "\"},\n   {\"descrizione\": \"" << _descrizione << "\"},\n   {\"costo\": \"" << _costo << "\"},\n";
//   return ss.str();
// } //=0

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
