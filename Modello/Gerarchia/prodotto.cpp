#include <string>
#include <sstream>
#include "prodotto.h"

Prodotto::Prodotto(unsigned short id, std::string nome, std::string descrizione, double prezzo)
  : _id(id)
  , _nome(nome)
  , _descrizione(descrizione)
  , _prezzo(prezzo)
  {}

Prodotto::~Prodotto() = default;

// // da spostare in classe serializzazione
// std::string Prodotto::mostraProdotto() const {
//   std::stringstream ss;
//   ss << "{ \"prodotto\" : [\n   {\"id\": \"" << _id  << "\"},\n   {\"nome\": \"" << _nome << "\"},\n   {\"descrizione\": \"" << _descrizione << "\"},\n   {\"prezzo\": \"" << _prezzo << "\"},\n";
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
double Prodotto::getPrezzo() const {
  return _prezzo;
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
void Prodotto::setPrezzo(double prezzo) {
  _prezzo = prezzo;
}