#ifndef SMARTP_H
#define SMARTP_H

#include "prodotto.h"

class SmartP {
  /* Aggiungere la seguente riga per renderlo utilizzabile da tutti i tipi:
     template<class T>
     prima della dichiarazione della classe e della implementazione dei metodi.
     Successivamente, sostituire le istanze di Prodotto con T
  */
  public:
    Prodotto* p;
    SmartP(Prodotto* q=nullptr);
    SmartP(const SmartP& s);
    ~SmartP();
    SmartP& operator=(const SmartP& s);
    bool operator==(const SmartP& s) const;
    Prodotto* operator->() const;
    Prodotto& operator*() const;
};

#endif // SMARTP_H
