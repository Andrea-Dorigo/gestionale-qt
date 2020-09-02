#ifndef VIVANDA_H
#define VIVANDA_H

#include "alimentare.h"

class Vivanda : public Alimentare {
private:
    std::string _sapore;
public:
    Vivanda(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, std::string sapore);
    virtual bool operator==(const Prodotto& prodotto) const override;
    virtual Vivanda* clone() const override;
    virtual double calcoloPrezzo() const override;
    virtual std::string stampa() const override;
    /* getters */
    std::string getSapore() const;
    virtual std::string getTipo() const override;
    /* setters */
    void setSapore(std::string sapore);
};

#endif // VIVANDA_H
