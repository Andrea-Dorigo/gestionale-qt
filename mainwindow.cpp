#include "mainwindow.h"
#include "insertwidget.h"
#include "delegate.h"
#include "tableview.h"
#include "tablemodeladapter.h"
#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QIcon>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    cmb_inserimento(new combobox_items(this, "Inserisci")),
    cmb_filtro(new combobox_items(this, "Nessuno")),
    searchbar(new QLineEdit(this)),
    proxymodel(new QFilterProxyModel(this)),
    model(new TableModelAdapter(this)),
    view(new TableView(this))
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
    searchfilterLayout->addRow(l, cmb_filtro);
    searchLayout->addLayout(searchfilterLayout);
    msearchLayout->addLayout(searchLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(cmb_inserimento);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(saveButton);

    // setup layouts
    mainLayout->addLayout(msearchLayout, 50);
    mainLayout->addLayout(buttonsLayout, 100); // stretch = 50 per distanziare i bottoni
    mainLayout->addWidget(view, 0, Qt::AlignCenter);

    // connect
    connect(cmb_inserimento, SIGNAL(currentTextChanged(QString)), this, SLOT(addProdotto(const QString&)));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeProdotto()));
    connect(searchbar, SIGNAL(textChanged(QString)), this, SLOT(textFilterChanged()));
    connect(cmb_filtro, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(clearSearchButton, SIGNAL(clicked()), searchbar, SLOT(clear()));
}

MainWindow::~MainWindow() {}

void MainWindow::addProdotto(const QString& t)
{
    if(t != "Inserisci")
    {
        insertWidget* inserisci = new insertWidget(t, this, view, proxymodel, model);
        cmb_inserimento->setCurrentText("Inserisci");
        inserisci->show();
    }
}

void MainWindow::removeProdotto()
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

void MainWindow::textFilterChanged()
{
   if(cmb_filtro->currentText() != "Nessuno")
        proxymodel->setFilter(cmb_filtro->currentText());
    else  proxymodel->setFilter("");
    QRegExp regex(searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    proxymodel->setFilterRegExp(regex);
}
