#ifndef INTEGRATORE_H
#define INTEGRATORE_H

#include "alimentare.h"

class Integratore : public Alimentare {
private:
    bool _dispositivoMedico;
public:
    Integratore(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string scadenza, bool dispositivoMedico);
    virtual bool operator==(const Prodotto&) const override;
    virtual Integratore* clone() const override;
    virtual double calcoloPrezzo() const override;
    virtual std::string stampa() const override;
    virtual void serialize(QXmlStreamWriter&) const;
    /* getters */
    bool getDispositivoMedico() const;
    virtual std::string getTipo() const override;
    /* setters */
    void setDispositivoMedico(bool);
};

#endif // INTEGRATORE_H
