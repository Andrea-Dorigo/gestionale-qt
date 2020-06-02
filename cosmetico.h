#ifndef COSMETICO_H
#define COSMETICO_H

#include <string>
//#include <map>
#include "prodotto.h"

enum Target {UOMO, DONNA, UNISEX};

// std::map<Target, std::string> TargetMapForward = {{UOMO, "Uomo"}, {DONNA, "donna"}, {UNISEX, "Unisex"}};

class Cosmetico : public Prodotto {
  private:
    Target _target;
    std::string _applicazione;
  public:
    Cosmetico(unsigned short id, std::string nome, std::string descrizione, double prezzo, Target target, std::string applicazione);
    virtual ~Cosmetico();
    virtual Cosmetico* clone() const;
    virtual double calcoloPrezzo() const;
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
