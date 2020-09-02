#include "fileio.h"
#include <QMessageBox>
#include <QDebug>
fileio::fileio(QString filename): filename(filename){}

Container<SmartP<Prodotto>> fileio::read() const
{
    Container<SmartP<Prodotto>> container;
    QFile file(filename);
     if(!file.open(QIODevice::ReadOnly))
    {
        qWarning() << "Non è stato possibile aprire il file" << file.errorString();
        return  container;
    }

    QXmlStreamReader reader(&file);
    if(reader.readNextStartElement() && reader.name() == "rootElement")
    {
        while(reader.readNextStartElement())
        {
            QXmlStreamAttributes classe= reader.attributes();

            std::string tipoClasse;
            unsigned short id;
            std::string nome;
            std::string descrizione;
            double costo;
            std::string ditta;
            int iva;

            if(classe.hasAttribute("tipo"))
                tipoClasse= classe.value("tipo").toString().toStdString();


            if(reader.readNextStartElement() && reader.name() == "id")
                id = reader.readElementText().toShort();
            if(reader.readNextStartElement() && reader.name() == "nome")
                nome = reader.readElementText().toStdString();
            if(reader.readNextStartElement() && reader.name() == "descrizione")
                descrizione = reader.readElementText().toStdString();
            if(reader.readNextStartElement() && reader.name() == "costo")
                costo = reader.readElementText().toDouble();
            if(reader.readNextStartElement() && reader.name() == "ditta")
                ditta = reader.readElementText().toStdString();
            if(reader.readNextStartElement() && reader.name() == "iva")
                iva = reader.readElementText().toDouble();

            // Individuazione tipo e istanziamento oggetto

            if(tipoClasse == "Cosmetico")
            {
                std::string target;
                std::string applicazione;

                if(reader.readNextStartElement() && reader.name() == "target")
                    target = reader.readElementText().toStdString();
                if(reader.readNextStartElement() && reader.name() == "applicazione")
                    applicazione = reader.readElementText().toStdString();

                Cosmetico* c = new Cosmetico(id,nome,descrizione,costo,ditta,iva,target,applicazione);
                container.push_back(SmartP<Prodotto>(c));
                delete c;
            }
            reader.skipCurrentElement();
        }
    }

    file.close();
    return container;
}

void fileio::write(const Container<SmartP<Prodotto>>& container) const
{
    QSaveFile file(filename);
    if(!file.open(QIODevice::WriteOnly))
    {
        QMessageBox b;
        b.setText(file.errorString());
        b.exec();
        throw std::exception();
    }

    QXmlStreamWriter writer(&file);
    writer.setAutoFormatting(true);
    writer.writeStartDocument();
    writer.writeStartElement("rootElement");

    Container<SmartP<Prodotto>>::const_iterator it= container.begin();
    for(; it != container.end(); ++it)
    {
        /*Scrittura sottoogetto non istanziabile "TeamMember"*/

        writer.writeStartElement("Prodotto");
        writer.writeAttribute("tipo",QString::fromStdString((*it)->getTipo()));
        /*Scrittura caratteristiche specifiche oggetto istanziabile*/
        (*it)->serialize(writer);
         writer.writeEndElement(); // <TeamMember type= (*cit)->getType()>
    }

    writer.writeEndElement();
    writer.writeEndDocument();
    file.commit();
    //scrive file temporaneo su disco se non ci sono stati
    //errori: discriminante sulla scelta di QSaveFile anziche QFile: scriverlo
    //nella relazione!!!!!!
}
//unsigned short _id;
//std::string _nome;
//std::string _descrizione;
//double _costo;
//std::string _ditta;
//int _iva;
