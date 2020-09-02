#ifndef TABLEMODELADAPTER_H
#define TABLEMODELADAPTER_H

#include "Modello/modello.h"
#include <QAbstractTableModel>

class TableModelAdapter: public QAbstractTableModel
{
private:
    Modello* _model;
    Prodotto* _nuovoProdotto;
public:
    TableModelAdapter(QObject* parent = nullptr);
    ~TableModelAdapter();
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    int columnCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role = 0) const override;
    QVariant headerData(int section = 0, Qt::Orientation orientation = Qt::Horizontal, int role = Qt::DisplayRole) const override;
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    bool matchFiltersSelected(unsigned int, const QRegExp&, const QString&) const;
    void setNuovoProdotto(Prodotto*);
    Prodotto* getNuovoProdotto();
    Prodotto& getProdotto(const QModelIndex &index) const;

    void saveToFile() const;
    void loadFromFile();
};

#endif // LISTMODELADAPTER_H
