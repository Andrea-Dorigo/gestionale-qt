#include "prodotto.h"

// template <>
// std::string attributeToString(unsigned short i){
//   return std::to_string(i);
// }
// template <>
// std::string attributeToString(std::string s){
//   return s;
// }
// template <>
// std::string attributeToString(double d){
//   return std::to_string(d);
// }

Prodotto::Prodotto(unsigned short id, std::string nome, std::string descrizione, double prezzo)
  : _id(id)
  , _nome(nome)
  , _descrizione(descrizione)
  , _prezzo(prezzo)
  {}
Prodotto::~Prodotto() {}

// Prodotto* Prodotto::clone() const {} //=0
// double Prodotto::calcoloPrezzo() const {} //=0
std::string Prodotto::mostraProdotto() const {
  std::stringstream ss;
  ss << "{ \"prodotto\" : [\n   {\"id\": \"" << _id  << "\"},\n   {\"nome\": \"" << _nome << "\"},\n   {\"descrizione\": \"" << _descrizione << "\"},\n   {\"prezzo\": \"" << _prezzo << "\"},\n";
  return ss.str();
} //=0

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
