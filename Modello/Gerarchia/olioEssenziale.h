#ifndef OLIOESSENZIALE_H
#define OLIOESSENZIALE_H

#include "cosmetico.h"
#include "vivanda.h"

class OlioEssenziale : public Cosmetico, Vivanda {
  private:
    std::string _profumazione;
  public:
    OlioEssenziale(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, std::string sapore, Target target, std::string applicazione, std::string profumazione);
    virtual bool operator==(const Prodotto& prodotto) const override;
    virtual OlioEssenziale* clone() const override;
    virtual double calcoloPrezzo() const override;
    virtual std::string stampa() const override;
    /* getters */
    std::string getProfumazione() const;
    /* setters */
    void setProfumazione(std::string profumazione);
};

#endif // OLIOESSENZIALE_H
