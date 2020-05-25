#include "cosmetico.h"
#include <iostream>

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Sesso sesso, string applicazione) :Prodotto(id, nome, descrizione, prezzo) _sesso(sesso), _applicazione(applicazione)  {}

Cosmetico* Cosmetico::clone() const {
  return new Cosmetico(*this);
}

double Cosmetico::calcoloPrezzo() const {
  return _prezzo;
}

string Cosmetico::mostraProdotto() const{
  return _applicazione;
}

Cosmetico::~Cosmetico() {}
