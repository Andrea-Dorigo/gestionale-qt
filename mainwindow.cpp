#include "mainwindow.h"

#include <QApplication>
#include <QDesktopWidget>
#include <QVBoxLayout>
#include <QIcon>
#include <QFormLayout>
#include <QLineEdit>
#include <QLabel>
#include <QPushButton>
#include <QMessageBox>
#include <QWidget>

MainWindow::MainWindow(QWidget *parent) :
    QWidget(parent),
    _cmb_inserimento(new combobox_items(this, "Inserisci")),
    _cmb_filtro(new combobox_items(this, "Nessuno")),
    _searchbar(new QLineEdit(this)),
    _proxymodel(new QFilterProxyModel(this)),
    _tablemodel(new TableModelAdapter(this)),
    _view(new TableView(this))
{
    // setup window
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
    setWindowTitle(("Magazzino - Erboristeria Alchimia"));
    setWindowIcon(QIcon(":/Risorse/logo_icona.png"));
    setFixedSize(QSize(1300, 800));

    _proxymodel->setSourceModel(_tablemodel);
    _view->setModel(_proxymodel);
    _view->setColumnWidth(0,50);    // id
    _view->setColumnWidth(1,150);   // ditta
    _view->setColumnWidth(2,250);   // nome
    _view->setColumnWidth(3,70);    // costo
    _view->setColumnWidth(4,60);    // iva
    _view->setColumnWidth(5,448);   // descrizione
    _view->setColumnWidth(6,60);    // target
    _view->setColumnWidth(7,448);   // applicazione
    _view->setColumnWidth(8,100);   // scadenza
    _view->setColumnWidth(9,140);   // dispositivo medico
    _view->setColumnWidth(10,300);  // sapore
    _view->setColumnWidth(11,250);  // profumazione

    _searchbar->setPlaceholderText("Ricerca per nome");
    QLabel* l = new QLabel("Filtro: ", this);

    QPushButton* removeButton = new QPushButton("Rimuovi", this);
    QPushButton* saveButton = new QPushButton("Salva", this);
    QPushButton* clearSearchButton = new QPushButton("X", this);

    // init layouts
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // _searchbar sottolayout
    QVBoxLayout* msearchLayout = new QVBoxLayout();
    QHBoxLayout* searchLayout = new QHBoxLayout();
    QFormLayout* searchfilterLayout= new QFormLayout();
    searchLayout->addWidget(_searchbar);
    searchLayout->addWidget(clearSearchButton);
    searchfilterLayout->addRow(l, _cmb_filtro);
    searchLayout->addLayout(searchfilterLayout);
    msearchLayout->addLayout(searchLayout);

    QHBoxLayout* buttonsLayout = new QHBoxLayout();
    buttonsLayout->addWidget(_cmb_inserimento);
    buttonsLayout->addWidget(removeButton);
    buttonsLayout->addWidget(saveButton);

    // setup layouts
    mainLayout->addLayout(msearchLayout, 50);
    mainLayout->addLayout(buttonsLayout, 100); // stretch = 50 per distanziare i bottoni
    mainLayout->addWidget(_view, 0, Qt::AlignCenter);

    // connect
    connect(_cmb_inserimento, SIGNAL(currentTextChanged(QString)), this, SLOT(addProdotto(const QString&)));
    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeProdotto()));
    connect(_searchbar, SIGNAL(textChanged(QString)), this, SLOT(textFilterChanged()));
    connect(_cmb_filtro, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));
    connect(clearSearchButton, SIGNAL(clicked()), _searchbar, SLOT(clear()));
}

MainWindow::~MainWindow() {}

void MainWindow::addProdotto(const QString& t)
{
    if(t != "Inserisci")
    {
        insertWidget* inserisci = new insertWidget(this, t, _view, _proxymodel, _tablemodel);
        _cmb_inserimento->setCurrentText("Inserisci");
        inserisci->show();
    }
}

void MainWindow::removeProdotto()
{
    // prende l'elenco degli elementi selezionati dalla _view
    const QModelIndexList selection = _view->selectionModel()->selectedIndexes();
    if(!selection.isEmpty())
    {
        _proxymodel->removeRows(selection.at(0).row(), 1);
        QMessageBox box;
        box.setText("Prodotto rimosso correttamente");
        box.exec();
    }
}

void MainWindow::textFilterChanged()
{ // maggiori info in TableModelAdapter::matchFiltersSelected()
    if(_cmb_filtro->currentText() != "Nessuno")
        _proxymodel->setFilter(_cmb_filtro->currentText());
    else  _proxymodel->setFilter("");
    QRegExp regex(_searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
    _proxymodel->setFilterRegExp(regex);
}
