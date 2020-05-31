#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include <list>
#include "prodotto.h"
#include "nlohmann/json.hpp"
#include "serialize.h"

class Magazzino {
private:
  class SmartP {
  public:
    Prodotto* p;
    SmartP(Prodotto* q);
    SmartP(const SmartP& s);
    SmartP& operator=(const SmartP& s);
    ~SmartP();
    Prodotto* operator->() const;
    Prodotto& operator*() const;
  };

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
