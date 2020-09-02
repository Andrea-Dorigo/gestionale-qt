#ifndef QFILTERPROXYMODEL_H
#define QFILTERPROXYMODEL_H

#include <QString>
#include <QSortFilterProxyModel>

/*
 * Classe intermediaria fra TableModelAdapter e TableView.
 * Permette la visualizzazione parziale degli elementi a seconda dell'input utente.
 * Non esegue operazioni sul modello reale.
*/

class QFilterProxyModel : public QSortFilterProxyModel {
private:
    QString _filter;

public:
    QFilterProxyModel(QObject* = nullptr, const QString& = "");
    bool insertRows(int, int = 1, const QModelIndex& = QModelIndex()) override;
    void setFilter(const QString&);
    bool filterAcceptsRow(int, const QModelIndex&) const override;
};

#endif // QFILTERPROXYMODEL_H
