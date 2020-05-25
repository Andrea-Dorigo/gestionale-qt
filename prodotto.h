#ifndef PRODOTTO_H
#define PRODOTTO_H

using std::string;

class Prodotto {
private:
  unsigned short _id;
  string _nome;
  string _descrizione;
  double _prezzo;
public:
  virtual Prodotto(unsigned short id, string nome, string descrizione, double prezzo=0.0);
  virtual Prodotto* clone() const=0;
  virtual double calcoloPrezzo() const=0;
  virtual string mostraProdotto() const=0;
  virtual ~Prodotto();
};

#endif // PRODOTTO_H
