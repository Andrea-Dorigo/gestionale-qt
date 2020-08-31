#ifndef INSERTWIDGET_H
#define INSERTWIDGET_H

#include "listview.h"
#include "listmodeladapter.h"
#include "qfilterproxymodel.h"
#include <QWidget>
#include <QString>
#include <QDialog>

class QLabel;
class QLineEdit;
class QSpinBox;
class QDoubleSpinBox;
class QComboBox;

class insertWidget: public QDialog
{
    Q_OBJECT
    private:
    const QString tipoOggetto;
    ListView* view;
    QFilterProxyModel* proxy;
    ListModelAdapter* model;
   /* QLabel* nome;
    QLabel* fisso;
    QLabel* bonus;
    QLabel* fruolo;
    QLabel* presenze;
    QLabel* sogliaPresenze;*/
    QLineEdit* barraNome;
    QComboBox* filtroRuolo;
    QDoubleSpinBox* scegliBase;
    QDoubleSpinBox* scegliBonus;
    QSpinBox* settaPresenze;
    QSpinBox* settaSogliaPresenze;

    public:
      insertWidget(const QString, QWidget* = nullptr,
                   ListView* = nullptr, QFilterProxyModel* = nullptr,
                   ListModelAdapter* = nullptr);
    private slots:
      void istanziaOggetto();
};

#endif // INSERTWIDGET_H
