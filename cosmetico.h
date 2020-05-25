#ifndef COSMETICO_H
#define COSMETICO_H
#include <string>

enum Sesso {Uomo, Donna, Unisex};

class Cosmetico {
private:
  Sesso _genere;
  std::string _applicazione;
public:
  // Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Sesso genere, std::string applicazione);
  Cosmetico(Sesso genere, std::string applicazione);
  // virtual Cosmetico* clone() const;
  // virtual double calcoloPrezzo() const;
  virtual std::string mostraProdotto() const;
  // virtual ~Cosmetico();
};

#endif // COSMETICO_H
