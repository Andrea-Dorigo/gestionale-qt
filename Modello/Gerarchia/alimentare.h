#ifndef ALIMENTARE_H
#define ALIMENTARE_H

#include "prodotto.h"

class Alimentare : virtual public Prodotto {
private:
    std::string _scadenza; // da rivedere
public:
    Alimentare(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza);
    virtual bool operator==(const Prodotto& prodotto) const override;
    virtual Alimentare* clone() const = 0;
    virtual double calcoloPrezzo() const = 0;
    virtual std::string stampa() const override;
    virtual void serialize(QXmlStreamWriter&) const;
    /* getters */
    std::string getScadenza() const;
    virtual std::string getTipo() const = 0;
    /* setters */
    void setScadenza(std::string scadenza);
};

#endif // ALIMENTARE_H
