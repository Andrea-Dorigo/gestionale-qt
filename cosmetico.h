#ifndef COSMETICO_H
#define COSMETICO_H
#include <string>
#include "prodotto.h"

using std::string;

enum Sesso {Uomo, Donna, Unisex};

class Cosmetico : public Prodotto {
private:
  Sesso _sesso;
  string _applicazione;
public:
  Cosmetico(unsigned short id, string nome, string descrizione, double prezzo, Sesso sesso, string applicazione);
  virtual Cosmetico* clone() const;
  virtual double calcoloPrezzo() const;
  virtual string mostraProdotto() const;
  virtual ~Cosmetico();
};

#endif // COSMETICO_H
