#ifndef COSMETICO_H
#define COSMETICO_H

#include "prodotto.h"

enum Target {UOMO, DONNA, UNISEX};

template <>
std::string attributeToString(Target t);


class Cosmetico : public Prodotto {
private:
  Target _target;
  std::string _applicazione;
public:
  Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Target target, std::string applicazione);
  virtual ~Cosmetico();

  virtual Cosmetico* clone() const;
  virtual double calcoloPrezzo() const;
  virtual std::string mostraProdotto() const;

};

#endif // COSMETICO_H
