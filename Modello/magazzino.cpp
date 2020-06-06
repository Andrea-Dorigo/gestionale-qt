#include "magazzino.h"
/*
#include "nlohmann/json.hpp"
#include "serialize.h"

bool Magazzino::insert(Prodotto* p) {
  sp.push_back(p);
  return true;
}

bool Magazzino::deleteProdotto(int id) {
  Prodotto* q = nullptr;
  auto it = sp.begin();
  // finché la lista non finisce oppure trovi il prodotto
  while(it != sp.end() || (*it)->getId() != id){
    it++;
  }
  if((*it)->getId() == id){
    it=sp.erase(it);
    return true;
  }
  else return false;
  // // metodo con ciclo for (meno efficiente)
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
*/
