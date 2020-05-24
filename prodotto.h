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

/*
class Alimentare : public Prodotto {
private:
  Data _scadenza;
public:
  virtual Alimentare(unsigned short id, string nome, string descrizione, double prezzo, Data scadenza);
  virtual Alimentare* clone() const=0;
  virtual double calcoloPrezzo() const=0;
  virtual string mostraProdotto() const=0;
  virtual ~Alimentare();
};
*/
//
//
// #ifndef PROFUMO_H
// #define PROFUMO_H
//
// #include "consumableitem.h"
// class Profumo: public ConsumableItem {
// private:
//     class StaticTableInit{
//     private:
//         Profumo* ptr;
//     public:
//         StaticTableInit();
//         ~StaticTableInit();
//     };
//     static StaticTableInit a;
//     std::string odore;
//     virtual Profumo* create(QXmlStreamReader&) const override;
// public:
//     Profumo(const std::string& ="No brand", const std::string& ="No name", const std::string& ="No info", float=0, float=1);
//
//     virtual void serialize(QXmlStreamWriter&) const override;
//
//     std::string getOdore() const;
//     void setOdore(const std::string& ="Inodore");
//     virtual std::string tipo() const override;
//     virtual Profumo* clone() const override;
// };
//
// #endif // PROFUMO_H
