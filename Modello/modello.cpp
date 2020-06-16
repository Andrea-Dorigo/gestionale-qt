#include "modello.h"

// void Modello::save(const std::string& filename) const {
//
// }
//
// void Modello::load(const std::string& filename) {
//
// }

unsigned int Modello::count() const {
  return magazzino.getSize();
}

void Modello::insert(Prodotto* p) {
  magazzino.push_back(p);
}

void Modello::remove(Prodotto* p) {
  auto it = magazzino.begin();
  if(magazzino.search(p, it)) magazzino.erase(it);
}

bool Modello::find(Prodotto* p) {
  auto it = magazzino.begin();
  return magazzino.search(p, it);
}

double Modello::costoTotale() {
  double sum = 0;
  for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
    sum += (it.p)->getCosto();
  }
  return sum;
}

double Modello::prezzoTotale() {
  double sum = 0;
  for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
    sum += (it.p)->calcoloPrezzo();
  }
  return sum;
}

int main(){return 0;}

// bool Modello::deleteProdotto(int id) {
//   Prodotto* q = nullptr;
//   auto it = sp.begin();
//   // finché la lista non finisce oppure trovi il prodotto
//   while(it != sp.end() || (*it)->getId() != id){
//     it++;
//   }
//   if((*it)->getId() == id){
//     it=sp.erase(it);
//     return true;
//   }
//   else return false;
//   // // metodo con ciclo for (meno efficiente)
//   // for (auto it = sp.begin(); it != sp.end(); it++){
//   //   if((*it)->getId() == id){
//   //     it=sp.erase(it);
//   //     //--it; non serve perche' tanto facciamo il return
//   //     return true;
//   //   }
//   //   else return false;
//   // }
// }
//
// bool Modello::mostraProdotto(Prodotto* p) {
//   Serialize s;
//   nlohmann::json prodotto;
//   prodotto["id"] = p->getId();
//   prodotto["nome"] = p->getNome();
//   prodotto["descrizione"] = p->getDescrizione();
//   prodotto["prezzo"] = p->getPrezzo();
//   s.Serialize::write("prodotto.json", prodotto);
//   return true;
// }
