#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>

/*
template <class Attribute>
std::string attributeToString(Attribute a) {return "tipo non trovato";}
template <>
std::string attributeToString(unsigned short i);
template <>
std::string attributeToString(std::string s);
template <>
std::string attributeToString(double d);
*/

class Prodotto {
private:
  unsigned short _id;
  std::string _nome;
  std::string _descrizione;
  double _prezzo;
public:
  Prodotto(unsigned short id, std::string nome, std::string descrizione, double prezzo=0.0);
  virtual ~Prodotto();
  virtual Prodotto* clone() const=0;
  virtual double calcoloPrezzo() const=0;
  /* da spostare in classe serializzazione */
  // virtual std::string mostraProdotto() const=0;
  /* getters */
  unsigned short getId() const;
  std::string getNome() const;
  std::string getDescrizione() const;
  double getPrezzo() const;
  /* setters */
  void setId(unsigned short id);
  void setNome(std::string nome);
  void setDescrizione(std::string descrizione);
  void setPrezzo(double prezzo);
};

#endif // PRODOTTO_H
