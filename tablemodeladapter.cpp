#include "tablemodeladapter.h"
#include "qtypeconversion.h"
#include <QPixmap>
#include <QColor>
#include <QBrush>
#include <typeinfo>
#include "Modello/Gerarchia/prodotto.h"

TableModelAdapter::TableModelAdapter(QObject* parent):
QAbstractTableModel(parent), model(new Modello()){}

TableModelAdapter::~TableModelAdapter()
{
    delete model;
}

int TableModelAdapter::rowCount(const QModelIndex &) const
{
    return model->count();
}
int TableModelAdapter::columnCount(const QModelIndex &) const
{
    return 10;
}

QVariant TableModelAdapter::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= model->count())
        return QVariant();

    else if (role == Qt::DisplayRole)
    {
        if (index.column() == 0)
            return QString::fromStdString(getProdotto(index).getDitta());
        else
            return QString::fromStdString(getProdotto(index).getNome());
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

//QVariant TableModelAdapter::headerData(int section, Qt::Orientation orientation, int role) const override {

//}



bool TableModelAdapter::mySetData(const QModelIndex &index,
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

Qt::ItemFlags TableModelAdapter::flags(const QModelIndex& index) const
{
    if (!index.isValid())
        return Qt::ItemIsEnabled;

    return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}


//chiamarla per eliminare un oggetto alla volta! (cosa obbligata
//visto che si puo selezionare un solo oggetto alla volta nella vista)
bool TableModelAdapter::removeRows(int begin, int count, const QModelIndex& parent)
{
    beginRemoveRows(parent, begin, begin + count - 1);
    model->remove(&model->getProdotto(static_cast<unsigned int> (begin)));
    endRemoveRows();
    return true;
}

// Inserisce 'count' nuove righe nel modello a partire dall'elemento di indice 'begin'
bool TableModelAdapter::insertRows(int begin, int count, const QModelIndex& parent)
{
    beginInsertRows(parent, begin, begin + count - 1);
        // effettuare l'aggiunta sul modello dei dati
    model->insert(nuovoElemento);
    endInsertRows();
    return true;
}

bool TableModelAdapter::
matchFiltersSelected(unsigned int i, const QRegExp& e, const QString& s) const
{
    std::string aux = (model->getProdotto(i)).getNome();
    if(!(QString::fromStdString(aux).contains(e)))
        return false;

    /*la riga in esame "matcha" il testo immesso nella QLineEdit*/
    if(!s.isEmpty())
    {
        if(s == "Cosmetico")
            return model->getProdotto(i).getTipo() == "Cosmetico";

        if(s == "Vivanda")
            return model->getProdotto(i).getTipo() == "Vivanda";
    }
    return true; //sse nessun Filtro selezionato ma c'é match QLineEdit
 }


Prodotto& TableModelAdapter::getProdotto(const QModelIndex &index) const
{
    return model->getProdotto(static_cast<unsigned int>(index.row()));
}

void TableModelAdapter::setNuovoElemento(Prodotto* p)
{
    nuovoElemento = p;
}

Prodotto* TableModelAdapter::getNuovoElemento()
{
    return nuovoElemento;
}

