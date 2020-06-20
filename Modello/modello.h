#ifndef MODELLO_H
#define MODELLO_H

#include <string>
#include "container.h"
#include "smartp.h"
#include "prodotto.h"

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
    double costoTotale(std::string ="") const;
    double prezzoTotale(std::string ="") const;
    bool find(Prodotto*);
};

#endif // MODELLO_H
