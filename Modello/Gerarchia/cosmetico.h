#ifndef COSMETICO_H
#define COSMETICO_H

#include "prodotto.h"

enum Target {UOMO, DONNA, UNISEX};

class Cosmetico : virtual public Prodotto {
  private:
    Target _target;
    std::string _applicazione;
  public:
    Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, Target target=UNISEX, std::string applicazione="");
    virtual bool operator==(const Prodotto&) const override;
    virtual Cosmetico* clone() const override;
    virtual double calcoloPrezzo() const override;
    /* getters */
    Target getTarget() const;
    std::string getApplicazione() const;
    /* setters */
    void setTarget(Target target);
    void setApplicazione(std::string applicazione);
};

#endif // COSMETICO_H
