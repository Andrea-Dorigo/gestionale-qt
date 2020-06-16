#ifndef MODELLO_H
#define MODELLO_H

#include "container.h"
#include "smartp.h"
#include "prodotto.h"

class Modello {
  private:
    Container<SmartP<Prodotto>> magazzino;
  public:
    Modello() = default;
    ~Modello() = default;
    // void save(const std::string&) const;
    // void load(const std::string&);
    unsigned int count() const;
    void insert(Prodotto*);
    void remove(Prodotto*);
    bool find(Prodotto*);
    double costoTotale(std::string="")
    double prezzoTotale(std::string="");
    // bool mostraProdotto(Prodotto*); // funzione da rimuovere da qui
};

#endif // MODELLO_H
