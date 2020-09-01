#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tableview.h"
#include "tablemodeladapter.h"
#include <QWidget>
#include "combobox_items.h"
#include "qfilterproxymodel.h"

class TableView;
class TableModelAdapter;
class QFilterProxyModel;

class MainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow() override;

private:
    combobox_items* cmb_inserimento;
    combobox_items* cmb_filtro;
    QLineEdit* searchbar;
    QFilterProxyModel* proxymodel;
    TableModelAdapter* model;
    TableView* view;
private slots:
    void addProdotto(const QString&);
    void removeProdotto();
    void textFilterChanged();
};

#endif // MAINWINDOW_H
