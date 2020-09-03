#include "fileio.h"
#include <QMessageBox>
#include <QDebug>

fileio::fileio(QString filename): _filename(filename){}

Container<SmartP<Prodotto>> fileio::read() const
{
    Container<SmartP<Prodotto>> container;
    QFile file(_filename);
    try {
       if(!file.open(QIODevice::ReadOnly)) throw std::exception();
    } catch(...) {
        qWarning() << "Impossibile aprire Risorse/data.xml";
        return container;
    }

    QXmlStreamReader xmlreader(&file);
    if(xmlreader.readNextStartElement() && xmlreader.name() == "rootElement")
    {
        while(xmlreader.readNextStartElement())
        {
            std::string tipoProdotto;
            unsigned short id = 0;
            std::string nome;
            std::string descrizione;
            double costo = 0.0;
            std::string ditta;
            int iva = 0;

            if(xmlreader.attributes().hasAttribute("tipo"))
                tipoProdotto = xmlreader.attributes().value("tipo").toString().toStdString();

            if(xmlreader.readNextStartElement() && xmlreader.name() == "id")
                id = xmlreader.readElementText().toShort();
            if(xmlreader.readNextStartElement() && xmlreader.name() == "nome")
                nome = xmlreader.readElementText().toStdString();
            if(xmlreader.readNextStartElement() && xmlreader.name() == "descrizione")
                descrizione = xmlreader.readElementText().toStdString();
            if(xmlreader.readNextStartElement() && xmlreader.name() == "costo")
                costo = xmlreader.readElementText().toDouble();
            if(xmlreader.readNextStartElement() && xmlreader.name() == "ditta")
                ditta = xmlreader.readElementText().toStdString();
            if(xmlreader.readNextStartElement() && xmlreader.name() == "iva")
                iva = xmlreader.readElementText().toDouble();

            if(tipoProdotto == "Cosmetico")
            {
                std::string target;
                std::string applicazione;

                if(xmlreader.readNextStartElement() && xmlreader.name() == "target")
                    target = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "applicazione")
                    applicazione = xmlreader.readElementText().toStdString();

                Cosmetico* c = new Cosmetico(id, nome, descrizione, costo, ditta, iva, target, applicazione);
                container.push_back(SmartP<Prodotto>(c));
                delete c;
            }
            else if(tipoProdotto == "Vivanda")
            {
                std::string scadenza;
                std::string sapore;

                if(xmlreader.readNextStartElement() && xmlreader.name() == "scadenza")
                    scadenza = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "sapore")
                    sapore = xmlreader.readElementText().toStdString();

                Vivanda* v = new Vivanda(id, nome, descrizione, costo, ditta, iva, scadenza, sapore);
                container.push_back(SmartP<Prodotto>(v));
                delete v;
            }
            else if(tipoProdotto == "Integratore")
            {
                std::string scadenza;
                bool dispositivoMedico = false;

                if(xmlreader.readNextStartElement() && xmlreader.name() == "scadenza")
                    scadenza = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "dispositivoMedico")
                    dispositivoMedico = xmlreader.readElementText().toInt();

                Integratore* i = new Integratore(id, nome, descrizione, costo, ditta, iva, scadenza, dispositivoMedico);
                container.push_back(SmartP<Prodotto>(i));
                delete i;
            }
            else if(tipoProdotto == "Olio essenziale")
            {
                std::string target;
                std::string applicazione;
                std::string scadenza;
                std::string sapore;
                std::string profumazione;

                if(xmlreader.readNextStartElement() && xmlreader.name() == "target")
                    target = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "applicazione")
                    applicazione = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "scadenza")
                    scadenza = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "sapore")
                    sapore = xmlreader.readElementText().toStdString();
                if(xmlreader.readNextStartElement() && xmlreader.name() == "profumazione")
                    profumazione = xmlreader.readElementText().toStdString();

                OlioEssenziale* o = new OlioEssenziale(id, nome, descrizione, costo, ditta, iva, scadenza, sapore, target, applicazione, profumazione);
                container.push_back(SmartP<Prodotto>(o));
                delete o;
            }
            xmlreader.skipCurrentElement();
        }
    }

    file.close();
    return container;
}

void fileio::write(const Container<SmartP<Prodotto>>& container) const
{
    QSaveFile file(_filename);
    try {
        if(!file.open(QIODevice::WriteOnly)) throw std::exception();
    } catch(...) {
        QMessageBox b;
        b.setText(file.errorString());
        b.exec();
    }

    QXmlStreamWriter xmlwriter(&file);
    xmlwriter.setAutoFormatting(true);
    xmlwriter.writeStartDocument();
    xmlwriter.writeStartElement("rootElement");

    Container<SmartP<Prodotto>>::const_iterator it = container.begin();
    for(; it != container.end(); ++it)
    {
        xmlwriter.writeStartElement("Prodotto");
        xmlwriter.writeAttribute("tipo", QString::fromStdString((*it)->getTipo()));
        (*it)->serialize(xmlwriter);
        xmlwriter.writeEndElement();
    }

    xmlwriter.writeEndElement();
    xmlwriter.writeEndDocument();
    file.commit();
}

