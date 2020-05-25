#include "cosmetico.h"

enum Sesso {Uomo, Donna, Unisex};

Cosmetico::Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Sesso genere, std::string applicazione) : _id(id), _nome(nome), _descrizione(descrizione), _prezzo(prezzo), genere(_genere), applicazione(_applicazione) {}
Cosmetico::Cosmetico* clone() const {}
Cosmetico::calcoloPrezzo() const {}
Cosmetico::mostraProdotto() const {
  std::cout << "ID: " << _id << " e nome: " << _nome << std::endline;
}
Cosmetico::~Cosmetico() {}
