#ifndef COSMETICO_H
#define COSMETICO_H

#include "prodotto.h"

enum Target { UOMO, DONNA, UNISEX };

class Cosmetico : virtual public Prodotto {
private:
    Target _target;
    std::string _applicazione;
public:
    Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, Target target = UNISEX, std::string applicazione = "");
    Cosmetico(unsigned short id, std::string nome, std::string descrizione, double costo, std::string ditta, int iva, std::string target = "UNISEX", std::string applicazione = "");
    virtual bool operator==(const Prodotto&) const override;
    virtual Cosmetico* clone() const override;
    virtual double calcoloPrezzo() const override;
    virtual std::string stampa() const override;
    virtual void serialize(QXmlStreamWriter&) const;
    std::string targetToString() const;
    /* getters */
    Target getTarget() const;
    std::string getApplicazione() const;
    virtual std::string getTipo() const override;
    /* setters */
    void setTarget(Target);
    void setApplicazione(std::string);
};

#endif // COSMETICO_H
