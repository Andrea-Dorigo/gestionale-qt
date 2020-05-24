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
  //costruttore
  virtual Prodotto(unsigned short id, string nome, string descrizione, double prezzo=0.0);
  //clone
  virtual Prodotto* clone() const=0;
  //calcola il prezzo del prodotto
  virtual double calcoloPrezzo() const=0;
  //
  virtual string mostraProdotto() const=0;
  virtual ~Prodotto();
};

#endif // PRODOTTO_H
