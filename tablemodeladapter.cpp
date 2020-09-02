#include "tablemodeladapter.h"
#include "Modello/Gerarchia/prodotto.h"
#include <QPixmap>
#include <QColor>
#include <QBrush>
#include <typeinfo>

TableModelAdapter::TableModelAdapter(QObject* parent):
    QAbstractTableModel(parent), _model(new Modello()){
}

TableModelAdapter::~TableModelAdapter()
{
    delete _model;
}

int TableModelAdapter::rowCount(const QModelIndex &) const
{
    return _model->count();
}
int TableModelAdapter::columnCount(const QModelIndex &) const
{
    return 12;
}

QVariant TableModelAdapter::data(const QModelIndex& index, int role) const
{
    unsigned int row = (short) index.row();
    if (!index.isValid() || row >= _model->count())
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
            Prodotto& prodotto = _model->getProdotto(row);

            if (index.column() == 6) {
                Cosmetico* cosmetico = dynamic_cast<Cosmetico*>(&prodotto);
                if(cosmetico)
                    return QString::fromStdString(cosmetico->targetToString());
            }
            else if (index.column() == 7) {
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
                    return QString::fromStdString(integratore->getDispositivoMedico() ? "SI" : "NO" );
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

QVariant TableModelAdapter::headerData(int section, Qt::Orientation, int role) const
{
    if (role != Qt::DisplayRole)
        return QVariant();
    if (section == 0)
        return QString::fromStdString("ID");
    if (section == 1)
        return QString::fromStdString("Ditta");
    if (section == 2)
        return QString::fromStdString("Nome");
    if (section == 3)
        return QString::fromStdString("Costo (€)");
    if (section == 4)
        return QString::fromStdString("IVA (%)");
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
    return QVariant();
}

bool TableModelAdapter::removeRows(int begin, int i, const QModelIndex& parent)
{
    beginRemoveRows(parent, begin, begin + i - 1);
    _model->remove(&_model->getProdotto(static_cast<unsigned int> (begin)));
    endRemoveRows();
    return true;
}

bool TableModelAdapter::insertRows(int begin, int i, const QModelIndex& parent)
{
    beginInsertRows(parent, begin, begin + i - 1);
    _model->insert(_nuovoProdotto);
    endInsertRows();
    return true;
}

bool TableModelAdapter::matchFiltersSelected(unsigned int i, const QRegExp& exp, const QString& filtro) const
{
    if(!(QString::fromStdString((_model->getProdotto(i)).getNome()).contains(exp)))
        return false;

    if(!filtro.isEmpty())
    {
        if(filtro == "Cosmetico")
            return _model->getProdotto(i).getTipo() == "Cosmetico";
        if(filtro == "Vivanda")
            return _model->getProdotto(i).getTipo() == "Vivanda";
        if(filtro == "Integratore")
            return _model->getProdotto(i).getTipo() == "Integratore";
        if(filtro == "Olio essenziale")
            return _model->getProdotto(i).getTipo() == "Olio essenziale";
    }
    return true; // nessun filtro selezionato ma risulta un match nella ricerca
}

Prodotto& TableModelAdapter::getProdotto(const QModelIndex &index) const
{
    return _model->getProdotto(static_cast<unsigned int>(index.row()));
}

void TableModelAdapter::setNuovoProdotto(Prodotto* p)
{
    _nuovoProdotto = p;
}

Prodotto* TableModelAdapter::getNuovoProdotto()
{
    return _nuovoProdotto;
}

