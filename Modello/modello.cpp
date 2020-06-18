#include "modello.h"

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

bool Modello::find(Prodotto* p) const {
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

int main(){return 0;}
