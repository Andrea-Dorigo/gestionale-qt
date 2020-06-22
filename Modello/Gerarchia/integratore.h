#ifndef INTEGRATORE_H
#define INTEGRATORE_H

#include "alimentare.h"

class Integratore : public Alimentare {
  private:
    bool _dispositivoMedico;
  public:
    Integratore(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, bool dispositivoMedico);
    virtual Integratore* clone() const override;
    virtual double calcoloPrezzo() const override;
    /* getters */
    bool getDispositivoMedico() const;
    /* setters */
    void setDispositivoMedico(bool dispositivoMedico);
};

#endif // INTEGRATORE_H
