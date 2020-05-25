#ifndef COSMETICO_H
#define COSMETICO_H

using std::string;

enum Sesso { "Uomo",
             "Donna",
             "Unisex" };

class Cosmetico {
private:
  Sesso _genere;
  string _applicazione;
public:
  virtual Cosmetico(unsigned short id, string nome, string descrizione, double prezzo, Sesso genere, string applicazione);
  virtual Cosmetico* clone();
  virtual double calcoloPrezzo();
  virtual string mostraCosmetico();
  virtual ~Cosmetico();
};

#endif // COSMETICO_H