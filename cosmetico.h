#ifndef COSMETICO_H
#define COSMETICO_H

enum Sesso {Uomo, Donna, Unisex};

class Cosmetico {
private:
  Sesso _genere;
  string _applicazione;
public:
  virtual Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Sesso genere, std::string applicazione);
  virtual Cosmetico* clone() const;
  virtual double calcoloPrezzo() const;
  virtual std::string mostraProdotto() const;
  virtual ~Cosmetico();
};

#endif // COSMETICO_H
