#ifndef VIVANDA_H
#define VIVANDA_H

#include "alimentare.h"

class Vivanda : public Alimentare {
  private:
    std::string _sapore;
  public:
    Vivanda(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, std::string scadenza, std::string dispositivoMedico);
    virtual bool operator==(const Prodotto&) const override;
    virtual Vivanda* clone() const override;
    virtual double calcoloPrezzo() const override;
    /* getters */
    std::string getSapore() const;
    /* setters */
    void setSapore(std::string sapore);
};

#endif // VIVANDA_H
