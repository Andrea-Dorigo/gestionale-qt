#include "smartp.h"

SmartP::SmartP(Prodotto* q)
  : p(q ? q->clone() : nullptr)
  {}

SmartP::SmartP(const SmartP& s)
  : p(s.p ? (s.p)->clone() : nullptr)
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
