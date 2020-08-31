#ifndef INSERTIONWIDGET_H
#define INSERTIONWIDGET_H

#include "listview.h"
#include "listmodeladapter.h"
#include "qfilterproxymodel.h"

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

class insertionWidget : public QDialog {
Q_OBJECT
private:
    const QString tipoOggetto;
    ListView* view;
    QFilterProxyModel* proxy;
    ListModelAdapter* model;

    QSpinBox* id_fld;
    QLineEdit* nome_fld;
    QLineEdit* descrizione_fld;
    QLineEdit* ditta_fld;
    QDoubleSpinBox* costo_fld;
    QSpinBox* iva_fld;
public:
    insertionWidget(const QString, QWidget* = nullptr,
                 ListView* = nullptr, QFilterProxyModel* = nullptr,
                 ListModelAdapter* = nullptr);
private slots:
  void istanziaOggetto();
};

#endif // INSERTIONWIDGET_H
