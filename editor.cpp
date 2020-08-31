#include "editor.h"
#include <QComboBox>
#include <QLabel>
#include <QSpinBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QtWidgets>
#include <QPushButton>

MyEditor::MyEditor(QWidget* parent):
    QDialog(parent) , l1(new QLabel("Contratto: ", this)),
    l2(new QLabel("Obiettivi: ", this)), l3(new QLabel("Presenze: ", this)),
    c1(new QComboBox(this)), c2(new QComboBox(this)) ,
  box(new QSpinBox(this)), button(new QPushButton("Conferma", this))
{

    c1->addItem("valido");
    c1->addItem("scaduto");
    c2->addItem("raggiunti");
    c2->addItem("non raggiunti");
    box->setRange(5, 25); //valori da leggere dal modello!!!

    //Layouts

    QVBoxLayout* v= new QVBoxLayout(this);
    QHBoxLayout* h1= new QHBoxLayout();
    QHBoxLayout* h2= new QHBoxLayout();
    QHBoxLayout* h3= new QHBoxLayout();

    h1->addWidget(l1);
    h1->addWidget(c1);
    h2->addWidget(l2);
    h2->addWidget(c2);
    h3->addWidget(l3);
    h3->addWidget(box);

    v->addLayout(h1);
    v->addLayout(h2);
    v->addLayout(h3);
    v->addWidget(button);

    connect(button, SIGNAL(clicked()), this, SIGNAL(editingFinished()));
}
