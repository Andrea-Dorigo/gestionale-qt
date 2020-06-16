#ifndef VIVANDA_H
#define VIVANDA_H

#include <string>
//#include <map>
#include "alimentare.h"


class Vivanda : public Alimentare {
  private:
    std::string _sapore;
  public:
    Vivanda(unsigned short id, std::string nome, std::string descrizione, double prezzo, std::string scadenza, std::string dispositivoMedico);
    virtual Vivanda* clone() const override;
    virtual double calcoloPrezzo() const override;
    // Vivanda& operator*() const;
    // virtual std::string mostraProdotto() const; // da spostare in classe serializzazione
    /* getters */
    std::string getSapore() const;
    /* setters */
    void setSapore(std::string sapore);
};

#endif // VIVANDA_H
