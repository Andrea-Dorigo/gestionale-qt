#include "tablemodeladapter.h"
#include "qtypeconversion.h"
#include <QPixmap>
#include <QColor>
#include <QBrush>
#include <typeinfo>
#include "Modello/Gerarchia/prodotto.h"

TableModelAdapter::TableModelAdapter(QObject* parent):
QAbstractTableModel(parent), model(new Modello()){
}

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
    return 12;
}

QVariant TableModelAdapter::data(const QModelIndex& index, int role) const
{
    if (!index.isValid() || index.row() >= model->count())
        return QVariant();

    if (role == Qt::DisplayRole) {

           if (index.column() == 0)
               return QString::number(getProdotto(index).getId());
           else if (index.column() == 1)
                return QString::fromStdString(getProdotto(index).getDitta());
           else if (index.column() == 2)
                return QString::fromStdString(getProdotto(index).getNome());
           else if (index.column() == 3)
                return QString::number(getProdotto(index).getCosto());
           else if (index.column() == 4)
                return QString::number(getProdotto(index).getIva());
           else if (index.column() == 5)
                return QString::fromStdString(getProdotto(index).getDescrizione());
           else {

               Prodotto& prodotto = model->getProdotto(static_cast<unsigned int>(index.row()));

               if (index.column() == 6){
                   Cosmetico* cosmetico = dynamic_cast<Cosmetico*>(&prodotto);
                   if(cosmetico)
                        return QString::fromStdString(cosmetico->targetToString());
               }
               else if (index.column() == 7){
                   Cosmetico* cosmetico = dynamic_cast<Cosmetico*>(&prodotto);
                   if(cosmetico)
                        return QString::fromStdString(cosmetico->getApplicazione());
               }
               else if (index.column() == 8) {
                   Alimentare* alimentare = dynamic_cast<Alimentare*>(&prodotto);
                   if(alimentare)
                        return QString::fromStdString(alimentare->getScadenza());
               }
               else if (index.column() == 9) {
                   Integratore* integratore = dynamic_cast<Integratore*>(&prodotto);
                   if(integratore)
                        return QString::number(integratore->getDispositivoMedico());
               }
               else if (index.column() == 10) {
                   Vivanda* vivanda = dynamic_cast<Vivanda*>(&prodotto);
                   if(vivanda)
                        return QString::fromStdString(vivanda->getSapore());
               }
               else if (index.column() == 11) {
                   OlioEssenziale* olioessenziale = dynamic_cast<OlioEssenziale*>(&prodotto);
                   if(olioessenziale)
                        return QString::fromStdString(olioessenziale->getProfumazione());
               }

               return QString::fromStdString("");

           }
    }
    else return QVariant();
}

QVariant TableModelAdapter::headerData(int section, Qt::Orientation orientation, int role) const {

    if (role != Qt::DisplayRole) return QVariant();

    if (section == 0)
            return QString::fromStdString("ID");
    if (section == 1)
            return QString::fromStdString("Ditta");
    if (section == 2)
            return QString::fromStdString("Nome");
    if (section == 3)
            return QString::fromStdString("Costo(€)");
    if (section == 4)
            return QString::fromStdString("Iva(%)");
    if (section == 5)
            return QString::fromStdString("Descrizione");
    if (section == 6)
            return QString::fromStdString("Target");
    if (section == 7)
            return QString::fromStdString("Applicazione");
    if (section == 8)
            return QString::fromStdString("Scadenza");
    if (section == 9)
            return QString::fromStdString("Dispositivo Medico");
    if (section == 10)
            return QString::fromStdString("Sapore");
    if (section == 11)
            return QString::fromStdString("Profumazione");
}


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

