#ifndef INTEGRATORE_H
#define INTEGRATORE_H

#include <string>
//#include <map>
#include "alimentare.h"


class Integratore : public Alimentare {
  private:
    bool _dispositivoMedico;
  public:
    Integratore(unsigned short id, std::string nome, std::string descrizione, double prezzo, std::string scadenza, bool dispositivoMedico);
    virtual Integratore* clone() const override;
    virtual double calcoloPrezzo() const override;
    // Integratore& operator*() const;
    // virtual std::string mostraProdotto() const; // da spostare in classe serializzazione
    /* getters */
    bool getDispositivoMedico() const;
    /* setters */
    void setDispositivoMedico(bool dispositivoMedico);
};

#endif // INTEGRATORE_H
