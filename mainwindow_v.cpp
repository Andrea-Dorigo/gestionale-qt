#include "mainwindow_v.h"
#include "insertwidget.h"
#include "delegate.h"
#include "listview.h"
#include "listmodeladapter.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QIcon>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

MainWindow_v::MainWindow_v(QWidget *parent) :
    QWidget(parent),
    cmb_ins(new combobox_inserimento(this)),
    filtro(new QComboBox(this)),
    searchbar(new QLineEdit(this)),
    proxymodel(new QFilterProxyModel(this)),
    model(new ListModelAdapter(this)),
    view(new ListView(this))
{
    // setup window
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setWindowTitle(("Magazzino - Erboristeria Alchimia"));
    setWindowIcon(QIcon(":/res/temp.jpg"));
    setFixedSize(QSize(1000, 600));


    proxymodel->setSourceModel(model);
    view->setModel(proxymodel);
//    view->setItemDelegate(new Delegate(view));

    searchbar->setPlaceholderText("Ricerca per nome");
    QLabel* l = new QLabel("Filtro: ", this);
    filtro->addItem("Nessuno");
    filtro->addItem("Cosmetico");
    filtro->addItem("Vivande");
    QPushButton* removeButton = new QPushButton("Rimuovi", this);
    QPushButton* saveButton = new QPushButton("Salva", this);
    QPushButton* clearSearchButton = new QPushButton("X", this);

    // init layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(this);


    // Searchbar sottolayout
    QVBoxLayout* msearchLayout = new QVBoxLayout();
    QHBoxLayout* searchLayout = new QHBoxLayout();
    QFormLayout* searchfilterLayout= new QFormLayout();
    searchLayout->addWidget(searchbar);
    searchLayout->addWidget(clearSearchButton);
    searchfilterLayout->addRow(l, filtro);
    searchLayout->addLayout(searchfilterLayout);
    msearchLayout->addLayout(searchLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(cmb_ins);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(saveButton);

    // setup layouts
    mainLayout->addLayout(msearchLayout, 50);
    mainLayout->addLayout(buttonsLayout, 100); // stretch = 50 per distanziare i bottoni
    mainLayout->addWidget(view, 0, Qt::AlignCenter);

    // connect
    connect(cmb_ins, SIGNAL(currentTextChanged(QString)), this, SLOT(addProdotto(const QString&)));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeProdotto()));
    connect(searchbar, SIGNAL(textChanged(QString)), this, SLOT(textFilterChanged()));
    connect(filtro, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(clearSearchButton, SIGNAL(clicked()), searchbar, SLOT(clear()));
}

MainWindow_v::~MainWindow_v() {}

void MainWindow_v::addProdotto(const QString& t)
{
//    if(t != "Inserisci")
//    {
//        insertWidget* inserisci = new insertWidget(t, this, view, proxymodel, model);
//        cmb_ins->setCurrentText("Inserisci");
//        inserisci->show();
//    }
}

void MainWindow_v::removeProdotto()
{
    // prende l'elenco degli elementi selezionati dalla view
    const QModelIndexList selection = view->selectionModel()->selectedIndexes();
    if(!selection.isEmpty())
    {
        QMessageBox box;
        proxymodel->removeRows(selection.at(0).row(), 1);
        box.setText("Membro selezionato rimosso correttamente");
        box.exec();
    }
}

void MainWindow_v::textFilterChanged()
{
   if(filtro->currentText() != "Nessuno")
        proxymodel->setFilter(filtro->currentText());
    else  proxymodel->setFilter("");
    QRegExp regex(searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxymodel->setFilterRegExp(regex);
}
