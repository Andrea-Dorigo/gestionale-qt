#include "insertionwidget.h"

insertionWidget::insertionWidget()
    : id_fld(new QDoubleSpinBox(this)),
      nome_fld(new QLineEdit(this)),
      descrizione_fld(new QLineEdit(this)),
      ditta_fld(new QLineEdit(this)),
      costo_fld(new QDoubleSpinBox(this)),
      iva_fld(new QDoubleSpinBox(this))
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
}
