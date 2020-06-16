#ifndef COSMETICO_H
#define COSMETICO_H

#include <string>
//#include <map>
#include "prodotto.h"

enum Target {UOMO, DONNA, UNISEX};

// std::map<Target, std::string> TargetMapForward = {{UOMO, "Uomo"}, {DONNA, "donna"}, {UNISEX, "Unisex"}};

class Cosmetico : virtual public Prodotto {
  private:
    Target _target;
    std::string _applicazione;
  public:
    Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, Target target=UNISEX, std::string applicazione="");
    virtual bool operator==(const Prodotto&) const override;
    virtual Cosmetico* clone() const override;
    virtual double calcoloPrezzo() const override;
    // Cosmetico& operator*() const;
    // virtual std::string mostraProdotto() const; // da spostare in classe serializzazione
    /* getters */
    Target getTarget() const;
    std::string getApplicazione() const;
    /* setters */
    void setTarget(Target target);
    void setApplicazione(std::string applicazione);
};

#endif // COSMETICO_H
