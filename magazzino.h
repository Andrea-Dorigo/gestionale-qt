#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include <list>
#include "prodotto.h"

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
  void mostraTutto();
};

#endif // MAGAZZINO_H
