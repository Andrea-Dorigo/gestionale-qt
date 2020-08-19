#ifndef MODELLO_H
#define MODELLO_H

#include <string>
#include "container.h"
#include "smartp.h"
#include "Gerarchia/prodotto.h"
#include "Gerarchia/cosmetico.h"
#include "Gerarchia/alimentare.h"
#include "Gerarchia/vivanda.h"

class Modello {
  private:
    Container<SmartP<Prodotto>> magazzino;
  public:
    Modello();
    ~Modello();
    // void save(const std::string&) const;
    // void load(const std::string&);
    unsigned int count() const;
    void insert(Prodotto*);
    void remove(Prodotto*);
    bool find(Prodotto*);
    double costoTotale(std::string ="") const; // TODO: rimuovere parametro
    double prezzoTotale(std::string ="") const;  // TODO: rimuovere parametro
    Container<SmartP<Prodotto>> filtra(std::string ditta="", double costo=0.0) const;
    std::string visualizza() const;
    Prodotto& getProdotto(unsigned int) const;
};

#endif // MODELLO_H
