#ifndef ALIMENTARE_H
#define ALIMENTARE_H

#include "prodotto.h"

class Alimentare : virtual public Prodotto {
  private:
    std::string _scadenza; // da rivedere
  public:
    Alimentare(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza);
    virtual Alimentare* clone() const =0;
    virtual double calcoloPrezzo() const =0;
    /* getters */
    std::string getScadenza() const;
    /* setters */
    void setScadenza(std::string scadenza);
};

#endif // ALIMENTARE_H
