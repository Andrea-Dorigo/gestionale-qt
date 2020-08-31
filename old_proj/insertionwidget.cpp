#include "insertionwidget.h"
#include <QLineEdit>
#include <QPushButton>
#include <QComboBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QLabel>
#include <QMessageBox>

#include <sstream>

insertionWidget::insertionWidget(const QString tipo, QWidget* parent,
                                 ListView* v,
                                 QFilterProxyModel* p,
                                 ListModelAdapter* m):
      QDialog(parent),tipoOggetto(tipo), view(v), model(m), proxy(p),
      id_fld(new QSpinBox(this)),
      nome_fld(new QLineEdit(this)),
      descrizione_fld(new QLineEdit(this)),
      ditta_fld(new QLineEdit(this)),
      costo_fld(new QDoubleSpinBox(this)),
      iva_fld(new QSpinBox(this))
{
    // creazione layout e oggetti di layout
    QVBoxLayout* mainLayout = new QVBoxLayout(this);
    QFormLayout* formLayout = new QFormLayout;
    QPushButton* conferma_btn = new QPushButton("Conferma", this);

    // creazione labels
    QLabel* id_lbl = new QLabel("ID: ", this);
    QLabel* nome_lbl = new QLabel("Nome: ", this);
    QLabel* descrizione_lbl = new QLabel("Descrizione: ", this);
    QLabel* ditta_lbl = new QLabel("Ditta: ", this);
    QLabel* costo_lbl = new QLabel("Costo: ", this);
    QLabel* iva_lbl = new QLabel("IVA: ", this);

    // aggiunta label/fields in formLayout
    formLayout->addRow(id_lbl, id_fld);
    formLayout->addRow(nome_lbl, nome_fld);
    formLayout->addRow(descrizione_lbl, descrizione_fld);
    formLayout->addRow(ditta_lbl, ditta_fld);
    formLayout->addRow(costo_lbl, costo_fld);
    formLayout->addRow(iva_lbl, iva_fld);

    // aggiunta oggetti in mainLayout
    mainLayout->addLayout(formLayout);
    mainLayout->addWidget(conferma_btn, Qt::AlignCenter);

    connect(conferma_btn, SIGNAL(clicked()), this, SLOT(istanziaOggetto()));
}


void insertionWidget::istanziaOggetto()
{
    QMessageBox box;
    Prodotto* m= nullptr;
    if(tipoOggetto == "Cosmetico")
    {
        m= new Cosmetico( id_fld->value(),
                          nome_fld->text().toStdString(),
                          descrizione_fld->text().toStdString(),
                          costo_fld->value(),
                          ditta_fld->text().toStdString(),
                          iva_fld->value(),
                          UOMO,
                          "spalmare in faccia"
                          );
    }
    if(tipoOggetto == "Vivanda")
    {
        m= new Vivanda( id_fld->value(),
                          nome_fld->text().toStdString(),
                          descrizione_fld->text().toStdString(),
                          costo_fld->value(),
                          ditta_fld->text().toStdString(),
                          iva_fld->value(),
                          "stringa",
                          "stringa"
                          );
    }
    if(m != nullptr)
    {
        int i =1;
        model->setNuovoElemento(m);
        proxy->insertRows(proxy->rowCount(), 1);
        i++;
        view->selectionModel()->clearCurrentIndex();
        view->clearSelection();
        view->selectionModel()->select(proxy->index(model->rowCount() - 1, 0),
                                                    QItemSelectionModel::Select);
        std::stringstream numeroProdotti;
        numeroProdotti << model->count();
        box.setText(QString::fromStdString(numeroProdotti.str()));

        box.exec();
        delete model->getNuovoElemento(); //elimino dallo heap la copia
        //dell'oggetto inserito nel contenitore del modello dei dati
    }

    else //caso in cui si aggiorni la comboBox e non il codice di questo slot!
        box.setText("L'elemento che si voleva inserire non e'"
                    "conosciuto!");
    close();
}
