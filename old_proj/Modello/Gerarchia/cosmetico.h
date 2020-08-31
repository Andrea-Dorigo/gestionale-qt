#ifndef COSMETICO_H
#define COSMETICO_H

#include "prodotto.h"

enum Target {UOMO, DONNA, UNISEX};

class Cosmetico : virtual public Prodotto {
  private:
    Target _target;
    std::string _applicazione;
  public:
    Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, Target target=UNISEX, std::string applicazione="");
    virtual bool operator==(const Prodotto& prodotto) const override;
    virtual Cosmetico* clone() const override;
    virtual double calcoloPrezzo() const override;
    virtual std::string stampa() const override;
    /* getters */
    Target getTarget() const;
    std::string getApplicazione() const;
    virtual std::string getTipo() const override;
    /* setters */
    void setTarget(Target target);
    void setApplicazione(std::string applicazione);
};

#endif // COSMETICO_H
