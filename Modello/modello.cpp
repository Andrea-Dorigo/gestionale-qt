#include "modello.h"
#include "cosmetico.h"

Modello::Modello() = default;

Modello::~Modello() = default;

// void Modello::save(const std::string& filename) const { }
// void Modello::load(const std::string& filename) { }

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

double Modello::costoTotale(std::string ditta) const {
  double sum = 0;
  if(ditta=="") {
    for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
      sum += (it->p)->getCosto();
    }
  }
  else {
    for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
      if(ditta == (it->p)->getDitta()) sum += (it->p)->getCosto();
    }
  }
  return sum;
}

double Modello::prezzoTotale(std::string ditta) const {
  double sum = 0;
  if(ditta=="") {
    for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
      sum += (it->p)->calcoloPrezzo();
    }
  }
  else {
    for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
      if(ditta == (it->p)->getDitta()) sum += (it->p)->calcoloPrezzo();
    }
  }
  return sum;
}

Container<SmartP<Prodotto>> Modello::filtra(std::string ditta, double costo) const {
  if(ditta=="" && costo==0.0) return magazzino; // più efficiente

  Container<SmartP<Prodotto>> aux;
  for(auto it = magazzino.begin(); it!=magazzino.end(); it++) {
    if(costo==0.0 || it->p->getCosto() < costo)
      if(ditta=="" || (it->p->getDitta() == ditta))
        aux.push_back(it->p);
  }
  return aux;
}
#include <iostream>
void Modello::MAGENTA() const {
  std::cout << magazzino.begin()->p->stampa() << std::endl;
  std::cout << magazzino.end()->p->stampa() << std::endl;
  // for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
  //   std::cout << it->p->stampa() << std::endl;
  // }
}

int main() {
  Modello m1;
  Cosmetico* c1 = new Cosmetico(1, "c1", "desc c1", 5.0, "Erbolario", UNISEX, "app c1");
  Cosmetico* c2 = new Cosmetico(2, "c2", "desc c2", 10.0, "Erbolario", UNISEX, "app c2");
  Cosmetico* c3 = new Cosmetico(3, "c3", "desc c3", 50.0, "Dardick", DONNA, "app c3");
  m1.insert(c1);
  m1.insert(c2);
  m1.insert(c3);
  m1.MAGENTA();
  return 0;
}
