#include "magazzino.h"

Magazzino::SmartP::SmartP(Prodotto* q=nullptr)
  : p(q!=nullptr ? q->clone() : nullptr)
  {}

Magazzino::SmartP::SmartP(const SmartP& s)
  : p(s.p !=nullptr ? (s.p)->clone() : nullptr)
  {}

SmartP& Magazzino::SmartP::operator=(const SmartP& s) {
  if(this != &s) {
    if(p) delete p;
    p = s.p !=nullptr ? (s.p)->clone() : nullptr;
  }
  return *this;
}
Magazzino::SmartP::~SmartP() {
  if(p) delete p;
}
Prodotto* Magazzino::SmartP::operator->() const {
  return p::
}
Prodotto& Magazzino::SmartP::operator*() const {
  return *p;
}

Magazzino::Magazzino() {}
void Magazzino::mostraTutto() {}
