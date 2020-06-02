#include <typeinfo>
#include "smartp.h"

SmartP::SmartP(Prodotto* q)
  : p(q!=nullptr ? q->clone() : nullptr)
  {}

SmartP::SmartP(const SmartP& s)
  : p(s.p!=nullptr ? (s.p)->clone() : nullptr)
  {}

SmartP::~SmartP() {
    if(p) delete p;
}

SmartP::SmartP& operator=(const SmartP& s) {
  if(this != &s) {
    if(p) delete p;
    p = (s.p!=nullptr ? (s.p)->clone() : nullptr);
  }
  return *this;
}

bool SmartP::operator==(const SmartP& s) const {
  return typeid(*p) == typeid(*s.p) && *p == *(s.p);
}
