#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "tableview.h"
#include "tablemodeladapter.h"
#include "combobox_items.h"
#include "qfilterproxymodel.h"
#include "insertwidget.h"

class TableView;
class TableModelAdapter;
class QFilterProxyModel;

class MainWindow : public QWidget
{
    Q_OBJECT

private:
    combobox_items* _cmb_inserimento;
    combobox_items* _cmb_filtro;
    QLineEdit* _searchbar;
    QFilterProxyModel* _proxymodel;
    TableModelAdapter* _tablemodel;
    TableView* _view;
    void loadData();

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow() override;

private slots:
    void saveData();
    void addProdotto(const QString&);
    void removeProdotto();
    void textFilterChanged();
};

#endif // MAINWINDOW_H
