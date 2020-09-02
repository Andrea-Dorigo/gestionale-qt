#ifndef FILEIO_H
#define FILEIO_H

#include "Modello/Gerarchia/prodotto.h"
#include "Modello/Gerarchia/alimentare.h"
#include "Modello/Gerarchia/cosmetico.h"
#include "Modello/Gerarchia/vivanda.h"
#include "Modello/Gerarchia/integratore.h"
#include "Modello/Gerarchia/olioEssenziale.h"
#include "Modello/container.h"
#include "Modello/smartp.h"

#include <QXmlStreamReader>
#include <QXmlStreamWriter>
#include <QFile>
#include <QSaveFile>
#include <QString>

class fileio
{
private:
    QString filename;
public:
    fileio(QString);
    Container<SmartP<Prodotto>> read() const;
    void write(const Container<SmartP<Prodotto>>&) const;
};

#endif // FILEIO_H
