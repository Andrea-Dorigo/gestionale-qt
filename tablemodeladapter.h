#ifndef TABLEMODELADAPTER_H
#define TABLEMODELADAPTER_H

#include "Modello/modello.h"
#include <QAbstractTableModel>

class TableModelAdapter: public QAbstractTableModel
{
  private:
    Modello* model;
    Prodotto* nuovoElemento;
  public:
    TableModelAdapter(QObject* parent= nullptr);
    ~TableModelAdapter();

    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role= Qt::DisplayRole) const override;
//    QVariant headerData(int section= 0, Qt::Orientation orientation= Qt::Horizontal, int role= Qt::DisplayRole) const override;


    Qt::ItemFlags flags(const QModelIndex&) const override;

    bool mySetData(const QModelIndex &index, const QVariant &value,
                   bool , bool =true, unsigned int=0);

    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool matchFiltersSelected(unsigned int, const QRegExp&, const QString&) const;
    void setNuovoElemento(Prodotto*);
    Prodotto* getNuovoElemento();
    Prodotto& getProdotto(const QModelIndex &index) const;
};

#endif // LISTMODELADAPTER_H
