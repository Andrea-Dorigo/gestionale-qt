#include "insertwidget.h"
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

insertWidget::insertWidget(const QString tipo, QWidget* parent,
                           ListView* v, QFilterProxyModel* p,
                           ListModelAdapter* m):
    QDialog(parent),tipoOggetto(tipo), view(v), proxy(p), model(m),
    /*nome(new QLabel("Nome: ", this)), fisso(new QLabel("Fisso: ", this)),
    bonus(new QLabel("Bonus: ", this)), fruolo(new QLabel("Ruolo: ", this)),
    presenze(new QLabel("Presenze: ", this)), sogliaPresenze(new QLabel("sogliaBonusPresenze: ", this)),
    */barraNome(new QLineEdit(this)), filtroRuolo(new QComboBox(this)),
    scegliBase(new QDoubleSpinBox(this)), scegliBonus(new QDoubleSpinBox(this)),
    settaPresenze(new QSpinBox(this)), settaSogliaPresenze(new QSpinBox(this))
{
    setGeometry(200, 150, 200, 150);
    setFixedSize(200, 150);

    QLabel* nome= new QLabel("Nome: ", this);
    QLabel* fisso= new QLabel("Fisso: ", this);
    QLabel* bonus= new QLabel("Bonus: ", this);
    QLabel* fruolo= new QLabel("Ruolo: ", this);
    QLabel* presenze= new QLabel("Presenze: ", this);
    QLabel* sogliaPresenze= new QLabel("sogliaBonusPresenze: ", this);

    if(tipoOggetto == "Cosmetico" ||
            tipoOggetto == "Vivanda")
    {
        fruolo->setVisible(false);
        filtroRuolo->setVisible(false);
        presenze->setVisible(false);
        settaPresenze->setVisible(false);
        sogliaPresenze->setVisible(false);
        settaSogliaPresenze->setVisible(false);
    }
    if(tipoOggetto == "Vivanda")
    {
        bonus->setVisible(false);
        scegliBonus->setVisible(false);
    }
    if(tipoOggetto == "Integratore") //Il tipo Calciatore ha tutti i filtri
    {
        setGeometry(200, 150, 200, 300);
        setFixedSize(300, 300);
    }
    QVBoxLayout* mainLayout= new QVBoxLayout(this);

    filtroRuolo->addItem(QString("Limone"));
    filtroRuolo->addItem(QString("Fragola"));
    filtroRuolo->addItem(QString("Frutti di bosco"));
    filtroRuolo->addItem(QString("Kiwi"));

    scegliBase->setRange(100000.00, 30000000.00);
    scegliBase->setSingleStep(10000);
    scegliBonus->setRange(0.0, 1000000.00);
    scegliBonus->setSingleStep(5000);
    settaPresenze->setRange(0, 60);
    settaSogliaPresenze->setRange(5, 25);

    QFormLayout* managerFiltri= new QFormLayout;
    managerFiltri->addRow(nome, barraNome);
    managerFiltri->addRow(fisso, scegliBase);
    managerFiltri->addRow(bonus, scegliBonus);
    managerFiltri->addRow(fruolo, filtroRuolo);
    managerFiltri->addRow(presenze, settaPresenze);
    managerFiltri->addRow(sogliaPresenze, settaSogliaPresenze);

    QPushButton* conferma= new QPushButton("Conferma ", this);

    mainLayout->addLayout(managerFiltri);
    mainLayout->addWidget(conferma, Qt::AlignCenter);

    connect(conferma, SIGNAL(clicked()), this, SLOT(istanziaOggetto()));
}


void insertWidget::istanziaOggetto()
{
    QMessageBox box;
    Prodotto* m = nullptr;

    if(tipoOggetto == "Cosmetico")
    {
         m = new Cosmetico(9, "nome_cos", "desc_cos", 69.420, "ditta_cos", 911, DONNA, "app_cos" );
    }

    else if(tipoOggetto == "Vivanda")
    {
        m = new Vivanda(1, "nome_viv", "desc_viv", 69.420, "ditta_viv", 911, "scad_viv", "sapore_viv" );

    }

    if(m != nullptr)
    {
        model->setNuovoElemento(m);
        proxy->insertRows(proxy->rowCount(), 1);
        view->clearSelection();
        view->selectionModel()->clearCurrentIndex();
        view->selectionModel()->select(proxy->index(model->rowCount() - 1, 0),
                                                    QItemSelectionModel::Select);

        box.setText("Elemento inserito con successo");
        box.exec();
        delete model->getNuovoElemento(); //elimino dallo heap la copia
        //dell'oggetto inserito nel contenitore del modello dei dati
    }
    else //caso in cui si aggiorni la comboBox e non il codice di questo slot!
        box.setText("L'elemento che si voleva inserire non e'"
                    "conosciuto!");
    close();
}

// mainWindow -> insertWidget -> listmodeladapter
// mainWindow -> insertWidget -> qfilterproxymodel -> listmodeladapter -> insertWidget -> mainWindow
