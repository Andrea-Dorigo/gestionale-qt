#ifndef MODELLO_H
#define MODELLO_H

#include "Gerarchia/prodotto.h"
#include "Gerarchia/alimentare.h"
#include "Gerarchia/cosmetico.h"
#include "Gerarchia/vivanda.h"
#include "Gerarchia/integratore.h"
#include "Gerarchia/olioEssenziale.h"
#include "container.h"
#include "smartp.h"

class Modello {
private:
    Container<SmartP<Prodotto>> magazzino;
public:
    Modello();
    ~Modello();
    unsigned int count() const;
    void insert(Prodotto*);
    void remove(Prodotto*);
    bool find(Prodotto*);
    double costoTotale(std::string = "") const;
    double prezzoTotale(std::string = "") const;
    Container<SmartP<Prodotto>> filtra(std::string ditta = "", double costo = 0.0) const;
    std::string visualizza() const;
    Prodotto& getProdotto(unsigned int) const;
};

#endif // MODELLO_H
