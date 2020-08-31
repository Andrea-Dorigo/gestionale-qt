#include "listmodeladapter.h"
#include "qtypeconversion.h"
#include <QPixmap>
#include <QColor>
#include <QBrush>
#include <typeinfo>
#include "Modello/Gerarchia/prodotto.h"

ListModelAdapter::ListModelAdapter(QObject* parent):
QAbstractListModel(parent), model(new Modello()){}

ListModelAdapter::~ListModelAdapter()
{
    delete model;
}

int ListModelAdapter::rowCount(const QModelIndex &) const
{
    return model->count();
}

QVariant ListModelAdapter::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= model->count())
        return QVariant();

    else if (role == Qt::DisplayRole)
    {
        return QString::fromStdString(getProdotto(index).stampa());
    }

    else if(role == Qt::DecorationRole)
    {
//        Prodotto& prodotto =
//                model->getProdotto(static_cast<unsigned int> (index.row()));
        QPixmap immagine = QPixmap(":/res/temp.jpg");

//        if(dynamic_cast<Allenatore*>(&membro))
//            immagine= QPixmap(":/resources/immagini/Allenatore.jpg");
//        else if(dynamic_cast<Calciatore*>(&membro))
//            immagine= QPixmap(":/resources/immagini/Calciatore.jpg");
//        else if(dynamic_cast<Dirigente*>(&membro))
//            immagine= QPixmap(":/resources/immagini/Dirigente.jpg");
        return immagine = immagine.scaled(100, 130);
    }
    else if(role == Qt::EditRole)
    {
        QVariant aux;
        aux.setValue(&model->getProdotto(static_cast<unsigned int>(index.row())));
        return aux;
    }
    else if (role == Qt::BackgroundColorRole)
        {
            if(index.row() % 2) //alterno colore oggetti consecutivi
                return QBrush(QColor(Qt::gray));// per distinguerli visivamente
            return QBrush(QColor(Qt::darkGray));
        }

    return QVariant();
}

bool ListModelAdapter::mySetData(const QModelIndex &index,
            const QVariant& val, bool contr, bool minObb, unsigned int p)
{
    if(!index.isValid() || !val.canConvert<QString>())
        return false;

//    Prodotto& aux = getProdotto(index);
//    aux.setContratto(contr);
//    if(val.toString() == "Allenatore")
//        static_cast<Allenatore&>(aux).setMinObiettiviStagionali(minObb);
//    else if(val.toString() == "Calciatore")
//        static_cast<Calciatore&>(aux).setPresenze(p);

//    emit dataChanged(index, index);

    return true;
}

Qt::ItemFlags ListModelAdapter::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractListModel::flags(index) | Qt::ItemIsEditable;
}


//chiamarla per eliminare un oggetto alla volta! (cosa obbligata
//visto che si puo selezionare un solo oggetto alla volta nella vista)
bool ListModelAdapter::removeRows(int begin, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent, begin, begin + count - 1);
    model->remove(&model->getProdotto(static_cast<unsigned int> (begin)));
    endRemoveRows();
    return true;
}

// Inserisce 'count' nuove righe nel modello a partire dall'elemento di indice 'begin'
bool ListModelAdapter::insertRows(int begin, int count, const QModelIndex& parent)
{
    beginInsertRows(parent, begin, begin + count - 1);
        // effettuare l'aggiunta sul modello dei dati
    model->insert(nuovoElemento);
    endInsertRows();
    return true;
}

bool ListModelAdapter::
matchFiltersSelected(unsigned int i, const QRegExp& e, const QString& s) const
{
    std::string aux = (model->getProdotto(i)).getNome();
    if(!(QString::fromStdString(aux).contains(e)))
        return false;

    /*la riga in esame "matcha" il testo immesso nella QLineEdit*/
    if(!s.isEmpty())
    {
        if(s == "Cosmetici")
            return model->getProdotto(i).getTipo() == "Cosmetico";

        if(s == "Vivande")
            return model->getProdotto(i).getTipo() == "Vivanda";
    }
    return true; //sse nessun Filtro selezionato ma c'é match QLineEdit
 }


Prodotto& ListModelAdapter::getProdotto(const QModelIndex &index) const
{
    return model->getProdotto(static_cast<unsigned int>(index.row()));
}

void ListModelAdapter::setNuovoElemento(Prodotto* p)
{
    nuovoElemento = p;
}

Prodotto* ListModelAdapter::getNuovoElemento()
{
    return nuovoElemento;
}

