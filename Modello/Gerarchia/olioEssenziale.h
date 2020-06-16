#ifndef OLIOESSENZIALE_H
#define OLIOESSENZIALE_H

#include <string>
//#include <map>
#include "cosmetico.h"
#include "vivanda.h"


class OlioEssenziale : public Cosmetico, Vivanda {
  private:
    std::string _profumazione;
  public:
    OlioEssenziale(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza, std::string sapore, Target target, std::string applicazione, std::string profumazione);
    virtual bool operator==(const Prodotto&) const override;
    virtual OlioEssenziale* clone() const override;
    virtual double calcoloPrezzo() const override;
    // OlioEssenziale& operator*() const;
    // virtual std::string mostraProdotto() const; // da spostare in classe serializzazione
    /* getters */
    std::string getProfumazione() const;
    /* setters */
    void setProfumazione(std::string profumazione);
};

#endif // OLIOESSENZIALE_H
