#include "container.h"
#include "smartp.h"
#include "prodotto.h"

class Magazzino {
  private:
    Container<SmartP<Prodotto>> magazzino;
  public:
    Magazzino() = default;
    ~Magazzino() = default;
    //inserisce un prodotto nel magazzino
    bool insert(Prodotto* p);
    //elimina il prodotto con un certo id
    bool deleteProdotto(int id);
    //funzione da rimuovere da qui
    bool mostraProdotto(Prodotto* p);
};
