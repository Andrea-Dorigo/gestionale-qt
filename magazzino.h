#ifndef MAGAZZINO_H
#define MAGAZZINO_H

#include "prodotti.h"

class Magazzino {
private:
  class SmartP {
  public:
    ICTstaff* p;
    SmartP(Prodotto* q=nullptr): p(q !=nullptr ? q->clone() : nullptr) {}
    SmartP(const SmartP& s): p(s.p !=nullptr ? (s.p)->clone() : nullptr) {}
    SmartP& operator=(const SmartP& s) {
      if(this != &s) {
	if(p) delete p;
	p = s.p !=nullptr ? (s.p)->clone() : nullptr;
      }
      return *this;
    }
    ~SmartP() {if(p) delete p;}
    Prodotto* operator->() const {return p;}
    Prodotto& operator*() const {return *p;}
  };
  std::list<SmartP> sp;
public:
  Magazzino();
  void MostraTutto();
};


#endif // MAGAZZINO_H
