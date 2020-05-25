#include "cosmetico.h"

enum Sesso {Uomo, Donna, Unisex};

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Sesso genere, std::string applicazione) : _id(id), _nome(nome), _descrizione(descrizione), _prezzo(prezzo), genere(_genere), applicazione(_applicazione) {}
Cosmetico* Cosmetico::clone() const {}
double Cosmetico::calcoloPrezzo() const {}
string Cosmetico::mostraProdotto() const {
  return "ID: " << _id << " e nome: " << _nome;
}
Cosmetico::~Cosmetico() {}
