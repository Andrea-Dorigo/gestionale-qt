#include "magazzino.h"

Magazzino::SmartP::SmartP(Prodotto* q)
  : p(q!=nullptr ? q->clone() : nullptr)
  {}

Magazzino::SmartP::SmartP(const SmartP& s)
  : p(s.p!=nullptr ? (s.p)->clone() : nullptr)
  {}

Magazzino::SmartP& Magazzino::SmartP::operator=(const SmartP& s) {
  if(this != &s) {
    if(p) delete p;
    p = (s.p!=nullptr ? (s.p)->clone() : nullptr);
  }
  return *this;
}

Magazzino::SmartP::~SmartP() {
  if(p) delete p;
}

Prodotto* Magazzino::SmartP::operator->() const {
  return p;
}

Prodotto& Magazzino::SmartP::operator*() const {
  return *p;
}
bool Magazzino::insert(Prodotto* p) {
  sp.push_back(p);
  return true;
}





bool Magazzino::mostraProdotto(Prodotto* p) {
  Serialize s;
  nlohmann::json prodotto;
  prodotto["id"] = p->getId();
  prodotto["nome"] = p->getNome();
  prodotto["descrizione"] = p->getDescrizione();
  prodotto["prezzo"] = p->getPrezzo();
  s.Serialize::write("prodotto.json", prodotto);
  return true;
}
