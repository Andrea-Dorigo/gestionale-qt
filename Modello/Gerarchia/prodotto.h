#ifndef PRODOTTO_H
#define PRODOTTO_H

#include <string>

class Prodotto {
  private:
    unsigned short _id;
    std::string _nome;
    std::string _descrizione;
    double _costo;
    std::string _ditta;
  public:
    Prodotto(unsigned short id=0, std::string nome="", std::string descrizione="", double costo=0.0, std::string ditta="");
    virtual ~Prodotto();
    virtual bool operator==(const Prodotto&) const;
    virtual Prodotto* clone() const=0;
    virtual double calcoloPrezzo() const=0;
    // virtual std::string mostraProdotto() const=0; // da spostare in classe serializzazione
    /* getters */
    unsigned short getId() const;
    std::string getNome() const;
    std::string getDescrizione() const;
    double getCosto() const;
    std::string getDitta() const;
    /* setters */
    void setId(unsigned short id);
    void setNome(std::string nome);
    void setDescrizione(std::string descrizione);
    void setCosto(double costo);
    void setDitta(std::string ditta);
};

#endif // PRODOTTO_H
