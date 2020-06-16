#ifndef ALIMENTARE_H
#define ALIMENTARE_H

#include <string>
//#include <map>
#include "prodotto.h"


class Alimentare : virtual public Prodotto {
  private:
    std::string _scadenza; // da rivedere
  public:
    Alimentare(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza);
    virtual bool operator==(const Prodotto&) const override;
    virtual Alimentare* clone() const =0;
    virtual double calcoloPrezzo() const =0;
    // virtual std::string mostraProdotto() const; // da spostare in classe serializzazione
    /* getters */
    std::string getScadenza() const;
    /* setters */
    void setScadenza(std::string scadenza);
};

#endif // ALIMENTARE_H
