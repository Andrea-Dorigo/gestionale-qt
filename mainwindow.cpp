


#include "mainwindow.h"
#include "listmodeladapter.h"
#include "listview.h"
//#include "qfilterproxymodel.h"
//#include "insertwidget.h"

#include <QDesktopWidget>
#include <QApplication>

#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QComboBox>
#include <QPushButton>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QMessageBox>
#include <QLineEdit>
#include <QLabel>
//#include "delegate.h"

MainWindow::MainWindow(QWidget *parent) : QWidget(parent),
//    inserimento(new QComboBox(this)),
//    filtro(new QComboBox(this)),
//    proxymodel(new QFilterProxyModel(this)),
    model(new ListModelAdapter(this)),
//    searchbar(new QLineEdit(this)),
    view(new ListView(this))
{

    // centra la finestra nello schermo
    move(QApplication::desktop()->screen()->rect().center() - rect().center());
/*    setWindowTitle(("Magazzino")); // titolo applicazione
    setWindowIcon(QIcon(":/resources/immagini/icona.png"));*/ // icona del programma

    // Widget a dimensione fissa non ridimensionabile
    setFixedSize(QSize(800, 400));

    // avvia caricamento del modello
//    loadData();

    // fornisce alla view il modello dei dati che deve riflettere
//    proxymodel->setSourceModel(modello);
    view->setModel(model);
//    view->setItemDelegate(new Delegate(view)); //delegate customizzato

    //Ricerca
//    searchbar->setPlaceholderText("Ricerca per nome");
//    QLabel* l= new QLabel("Filtro: ", this);
//    filtro->addItem("Nessuno");
//    filtro->addItem("Dirigente");
//    filtro->addItem("Calciatore");
//    filtro->addItem("Allenatore");

    // PULSANTI
//    inserimento->addItem("Inserisci");
//    inserimento->addItem("Dirigente");
//    inserimento->addItem("Calciatore");
//    inserimento->addItem("Allenatore");
//    QPushButton* removeButton = new QPushButton("Rimuovi", this);
//    QPushButton* saveButton = new QPushButton("Salva", this);
//    QPushButton* clearSearchButton = new QPushButton("X", this);


    // MENÙ e MENUBAR
//    QMenuBar* menuBar = new QMenuBar();
//    QMenu* menu = new QMenu("File", menuBar);
//    QAction* saveAction = new QAction("Salva", menu);
//    QAction* exitAction = new QAction("Esci", menu);
//    // Setup del menù
//    menuBar->addMenu(menu);
//    menu->addAction(saveAction);
//    menu->addAction(exitAction);

    // LAYOUT
    QVBoxLayout* mainLayout = new QVBoxLayout(this);

    // Searchbar sottolayout
//    QVBoxLayout* msearchLayout = new QVBoxLayout();
//    QHBoxLayout* searchLayout = new QHBoxLayout();
//    QFormLayout* searchfilterLayout= new QFormLayout();
//    searchLayout->addWidget(searchbar);
//    searchLayout->addWidget(clearSearchButton);
//    searchfilterLayout->addRow(l, filtro);
//    searchLayout->addLayout(searchfilterLayout);
//    msearchLayout->addLayout(searchLayout);

    // Pulsanti sottolayout
//    QHBoxLayout* buttonsLayout = new QHBoxLayout();
//    buttonsLayout->addWidget(inserimento);
//    buttonsLayout->addWidget(removeButton);
//    buttonsLayout->addWidget(saveButton);

    // Setup Main layout
/*    mainLayout->addWidget(menuBar);*/ // stretch = 50 per distanziare i bottoni
//    mainLayout->addLayout(msearchLayout, 50);
/*    mainLayout->addLayout(buttonsLayout, 100);*/ // stretch = 50 per distanziare i bottoni
    mainLayout->addWidget(view, 0, Qt::AlignCenter);

    // CONNECT
//    connect(saveButton, SIGNAL(clicked()), this, SLOT(saveData()));
//    connect(saveAction, SIGNAL(triggered()), this, SLOT(saveData()));
//    connect(exitAction, SIGNAL(triggered()), this, SLOT(close()));
//    connect(inserimento, SIGNAL(currentTextChanged(QString)), this, SLOT(addMembroSocieta(const QString&)));
//    connect(removeButton, SIGNAL(clicked()), this, SLOT(removeMembroSocieta()));
//    connect(searchbar, SIGNAL(textChanged(QString)), this, SLOT(textFilterChanged()));
//    connect(filtro, SIGNAL(currentTextChanged(const QString&)), this, SLOT(textFilterChanged()));
//    connect(clearSearchButton, SIGNAL(clicked()), searchbar, SLOT(clear()));
}

// NB: non distrugge i QWidget (di quello se ne occupa Qt)
MainWindow::~MainWindow() {}

/*
 * Ritorna la dimensione ottimale della finestra
 */
QSize MainWindow::sizeHint() const
{
    return QSize(800, 800);
}


//void MainWindow::saveData()
//{
//    try
//    {
//        model->saveToFile();
//    }
//    catch (std::exception)
//    {
//        QMessageBox box(QMessageBox::Warning, "Errore di salvataggio", "Non è stato possibile scrivere sul file", QMessageBox::Ok);
//        box.exec();
//        return;
//    }
//    QMessageBox box;
//    box.setText("Salvataggio effettuato");
//    box.exec();
//}

//void MainWindow::loadData()
//{
//    // in tale caso non serve passare per il proxymodel
//    model->loadFromFile();
//}


//void MainWindow::addMembroSocieta(const QString& t)
//{
//    if(t != "Inserisci")
//    {
//        insertWidget* inserisci= new insertWidget(t, this, view, proxymodel, model);
//        inserimento->setCurrentText("Inserisci");
//        inserisci->show();
//    }
//}


//void MainWindow::removeMembroSocieta()
//{
//    // prende l'elenco degli elementi selezionati dalla view
//    const QModelIndexList selection = view->selectionModel()->selectedIndexes();
//    if(!selection.isEmpty())
//    {
//        QMessageBox box;
//        if(!model->isContrattoScaduto(selection.at(0)))
//            box.setText("Impossibile rimuovere il membro selezionato:"
//                    " ha un contratto in corso di validita'!");
//        else
//        {
//            proxymodel->removeRows(selection.at(0).row(), 1);
//            box.setText("Membro selezionato rimosso correttamente");
//        }
//        box.exec();
//    }
//}

//void MainWindow::textFilterChanged()
//{
//    if(filtro->currentText() != "Nessuno")
//        proxymodel->setFilter(filtro->currentText());
//    else  proxymodel->setFilter("");
//    QRegExp regex(searchbar->text(), Qt::CaseInsensitive, QRegExp::Wildcard);
//    proxymodel->setFilterRegExp(regex);
//}

