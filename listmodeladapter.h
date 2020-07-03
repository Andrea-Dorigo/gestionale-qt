#ifndef LISTMODELADAPTER_H
#define LISTMODELADAPTER_H

#include "Modello/modello.h"
#include<QAbstractListModel>

class ListModelAdapter: public QAbstractListModel
{
  private:
    Modello* modello;
    Prodotto* nuovoElemento;
  public:
    ListModelAdapter(QObject* = nullptr);
    ~ListModelAdapter();
    int rowCount(const QModelIndex& = QModelIndex()) const override;
    QVariant data(const QModelIndex &index, int role= Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex&) const override;

//    bool mySetData(const QModelIndex &index, const QVariant &value,
//                   bool , bool =true, unsigned int=0);

//    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
//    bool removeRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
//    bool matchFiltersSelected(unsigned int, const QRegExp&, const QString&) const;
//    unsigned int getNumCalciatori() const;
//    unsigned int getMaxCalciatoriRosa() const;
//    void setNuovoElemento(membroSocieta*);
//    membroSocieta* getNuovoElemento();
//    bool allenatorePresente() const;
//    void saveToFile() const;
//    void loadFromFile();
//    bool isContrattoScaduto(const QModelIndex &index) const;
//    membroSocieta& getMembro(const QModelIndex &index) const;
};

#endif // LISTMODELADAPTER_H
