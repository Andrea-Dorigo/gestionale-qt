#ifndef INSERTWIDGET_H
#define INSERTWIDGET_H

#include "tableview.h"
#include "qfilterproxymodel.h"
#include "tablemodeladapter.h"
#include "combobox_target.h"
#include "combobox_sn.h"
#include <QDialog>
#include <QSpinBox>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QDateEdit>
#include <QWidget>
#include <QString>

class insertWidget: public QDialog
{
    Q_OBJECT
private:
    const QString _tipoProdotto;
    TableView* _view;
    QFilterProxyModel* _proxymodel;
    TableModelAdapter* _tablemodel;
    QSpinBox* _fld_id;
    QLineEdit* _fld_nome;
    QLineEdit* _fld_descrizione;
    QLineEdit* _fld_ditta;
    QDoubleSpinBox* _fld_costo;
    QSpinBox* _fld_iva;
    combobox_target* _fld_target;
    QLineEdit* _fld_applicazione;
    QDateEdit* _fld_scadenza;
    QLineEdit* _fld_sapore;
    combobox_sn* _fld_dispositivoMedico;
    QLineEdit* _fld_profumazione;

public:
    insertWidget(QWidget* = nullptr, const QString = "", TableView* = nullptr, QFilterProxyModel* = nullptr, TableModelAdapter* = nullptr);

private slots:
    void istanziaProdotto();
};

#endif // INSERTWIDGET_H
