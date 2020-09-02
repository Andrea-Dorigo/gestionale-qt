#include "modello.h"

Modello::Modello() {}

Modello::~Modello() {}



void Modello::saveToFile() const
{
    fileio xml("../progetto-p2/Risorse/data.xml");
    xml.write(magazzino);
}

void Modello::loadFromFile()
{
    fileio xml("../progetto-p2/Risorse/data.xml");
    magazzino = xml.read();
}


unsigned int Modello::count() const {
    return magazzino.getSize();
}

void Modello::insert(Prodotto* p) {
    magazzino.push_back(p);
}

void Modello::remove(Prodotto* p) {
    auto it = magazzino.begin();
    if(magazzino.search(p, it)) magazzino.erase(it);
}

bool Modello::find(Prodotto* p) {
    auto it = magazzino.begin();
    return magazzino.search(p, it);
}

double Modello::costoTotale(std::string ditta) const {
    double sum = 0;
    if(ditta=="") {
        for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
            sum += (it->p)->getCosto();
        }
    }
    else {
        for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
            if(ditta == (it->p)->getDitta()) sum += (it->p)->getCosto();
        }
    }
    return sum;
}

double Modello::prezzoTotale(std::string ditta) const {
    double sum = 0;
    if(ditta == "") {
        for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
            sum += (it->p)->calcoloPrezzo();
        }
    }
    else {
        for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
            if(ditta == (it->p)->getDitta()) sum += (it->p)->calcoloPrezzo();
        }
    }
    return sum;
}

Container<SmartP<Prodotto>> Modello::filtra(std::string ditta, double costo) const {
    if(ditta == "" && costo == 0.0) return magazzino; // più efficiente

    Container<SmartP<Prodotto>> aux;
    for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
        if(costo == 0.0 || it->p->getCosto() < costo)
            if(ditta == "" || (it->p->getDitta() == ditta))
                aux.push_back(it->p);
    }
    return aux;
}

std::string Modello::visualizza() const {
    std::stringstream result ;
    for(auto it = magazzino.begin(); it != magazzino.end(); it++) {
        result << it->p->stampa();
    }
    return result.str();
}

Prodotto& Modello::getProdotto(unsigned int i) const
{
    return const_cast<Prodotto&>(**(magazzino.begin() + i));
}
