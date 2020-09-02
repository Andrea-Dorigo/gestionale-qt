#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>
#include <sstream>
#include<QXmlStreamWriter>
class Prodotto {
private:
    unsigned short _id;
    std::string _nome;
    std::string _descrizione;
    double _costo;
    std::string _ditta;
    int _iva;
public:
    Prodotto(unsigned short id = 0, std::string nome = "", std::string descrizione = "", double costo = 0.0, std::string ditta = "", int iva = 22);
    virtual ~Prodotto();
    virtual bool operator==(const Prodotto& prodotto) const;
    virtual Prodotto* clone() const = 0;
    virtual double calcoloPrezzo() const = 0;
    virtual std::string stampa() const;
    /* getters */
    unsigned short getId() const;
    std::string getNome() const;
    std::string getDescrizione() const;
    double getCosto() const;
    std::string getDitta() const;
    int getIva() const;
    virtual std::string getTipo() const = 0;
    /* setters */
    void setId(unsigned short id);
    void setNome(std::string nome);
    void setDescrizione(std::string descrizione);
    void setCosto(double costo);
    void setDitta(std::string ditta);
    void setIva(int iva);


    virtual void serialize(QXmlStreamWriter&) const;
};

#endif // PRODOTTO_H
