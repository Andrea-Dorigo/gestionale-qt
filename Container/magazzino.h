#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include <list>
#include "smartp.h"
#include "prodotto.h"

class Magazzino {
  private:
    std::list<SmartP> sp;
  public:
    //inserisce un prodotto nel magazzino
    bool insert(Prodotto* p);
    //elimina il prodotto con un certo id
    bool deleteProdotto(int id);
    //funzione da rimuovere da qui
    bool mostraProdotto(Prodotto* p);
};

#endif // MAGAZZINO_H
