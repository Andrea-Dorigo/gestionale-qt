#include "prodotto.h"

Prodotto::Prodotto(unsigned short id, std::string nome, std::string descrizione, double prezzo) : _id(id), _nome(nome), _descrizione(descrizione), _prezzo(prezzo){}

Prodotto::~Prodotto(){}
