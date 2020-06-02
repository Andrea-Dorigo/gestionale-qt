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

bool Magazzino::deleteProdotto(int id) {
  Prodotto* q = nullptr;
  auto it = sp.begin();
  /* finché la lista non finisce oppure trovi il prodotto */
  while(it != sp.end() || (*it)->getId() != id)){
    it++;
  }
  if((*it)->getId() == id){
    it=sp.erase(it);
    return true;
  }
  else return false;
  // for (auto it = sp.begin(); it != sp.end(); it++){
  //   if((*it)->getId() == id){
  //     it=sp.erase(it);
  //     //--it; non serve perche' tanto facciamo il return
  //     return true;
  //   }
  //   else return false;
  // }
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
