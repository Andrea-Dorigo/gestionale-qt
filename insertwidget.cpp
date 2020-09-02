#include "insertwidget.h"
#include <QPushButton>
#include <QFormLayout>
#include <QVBoxLayout>
#include <QMessageBox>

insertWidget::insertWidget(QWidget* parent, const QString tipoProdotto, TableView* view, QFilterProxyModel* proxymodel, TableModelAdapter* tablemodel)
    : QDialog(parent), _tipoProdotto(tipoProdotto), _view(view), _proxymodel(proxymodel), _tablemodel(tablemodel)
    , _fld_id(new QSpinBox(this))
    , _fld_nome(new QLineEdit(this))
    , _fld_descrizione(new QLineEdit(this))
    , _fld_ditta(new QLineEdit(this))
    , _fld_costo(new QDoubleSpinBox(this))
    , _fld_iva(new QSpinBox(this))
    , _fld_target(new combobox_target(this))
    , _fld_applicazione(new QLineEdit(this))
    , _fld_scadenza(new QDateEdit(this))
    , _fld_sapore(new QLineEdit(this))
    , _fld_dispositivoMedico(new combobox_sn(this))
    , _fld_profumazione(new QLineEdit(this))
{
    setWindowTitle(_tipoProdotto + " - Erboristeria Alchimia");
    setGeometry(200, 150, 300, 310);
    setFixedSize(300, 310);

    // init items
    QLabel* lbl_id = new QLabel("Cod. ID: ", this);
    QLabel* lbl_nome = new QLabel("Nome: ", this);
    QLabel* lbl_descrizione = new QLabel("Descrizione: ", this);
    QLabel* lbl_ditta = new QLabel("Ditta: ", this);
    QLabel* lbl_costo = new QLabel("Costo: ", this);
    QLabel* lbl_iva = new QLabel("IVA: ", this);
    QPushButton* btn_conferma = new QPushButton("Conferma ", this);
    QFormLayout* lout_form = new QFormLayout;
    QVBoxLayout* lout_main = new QVBoxLayout(this);

    // setup items
    _fld_id->setValue(_tablemodel->rowCount()+1); // cod. identificativo automatico
    _fld_id->setEnabled(false);
    _fld_costo->setRange(0.00, 999.99);
    _fld_iva->setRange(0, 100);
    // fields non comuni
    _fld_target->setVisible(false);
    _fld_applicazione->setVisible(false);
    _fld_scadenza->setVisible(false);
    _fld_sapore->setVisible(false);
    _fld_dispositivoMedico->setVisible(false);
    _fld_profumazione->setVisible(false);

    // linking label <=> field
    lout_form->addRow(lbl_id, _fld_id);
    lout_form->addRow(lbl_nome, _fld_nome);
    lout_form->addRow(lbl_descrizione, _fld_descrizione);
    lout_form->addRow(lbl_ditta, _fld_ditta);
    lout_form->addRow(lbl_costo, _fld_costo);
    lout_form->addRow(lbl_iva, _fld_iva);

    if(_tipoProdotto == "Cosmetico")
    { // Target _target, std::string _applicazione
        QLabel* lbl_target = new QLabel("Target: ", this);
        QLabel* lbl_applicazione = new QLabel("Applicazione: ", this);
        _fld_target->setVisible(true);
        _fld_applicazione->setVisible(true);
        lout_form->addRow(lbl_target, _fld_target);
        lout_form->addRow(lbl_applicazione, _fld_applicazione);
    }
    else if(_tipoProdotto == "Vivanda")
    { // std::string scadenza, std::string sapore
        QLabel* lbl_scadenza = new QLabel("Scadenza: ", this);
        QLabel* lbl_sapore = new QLabel("Sapore: ", this);
        _fld_scadenza->setDate(QDate::currentDate().addDays(1));
        _fld_scadenza->setVisible(true);
        _fld_sapore->setVisible(true);
        lout_form->addRow(lbl_scadenza, _fld_scadenza);
        lout_form->addRow(lbl_sapore, _fld_sapore);
    }
    else if(_tipoProdotto == "Integratore")
    { // std::string scadenza, bool dispositivoMedico
        QLabel* lbl_scadenza = new QLabel("Scadenza: ", this);
        QLabel* lbl_dispositivoMedico = new QLabel("Dispositivo medico: ", this);
        _fld_scadenza->setDate(QDate::currentDate().addDays(1));
        _fld_scadenza->setVisible(true);
        _fld_dispositivoMedico->setVisible(true);
        lout_form->addRow(lbl_scadenza, _fld_scadenza);
        lout_form->addRow(lbl_dispositivoMedico, _fld_dispositivoMedico);
    }
    else if(_tipoProdotto == "Olio essenziale")
    { // std::string scadenza, std::string sapore, Target target, std::string applicazione, std::string profumazione
        setGeometry(200, 150, 300, 400);
        setFixedSize(300, 400);
        QLabel* lbl_scadenza = new QLabel("Scadenza: ", this);
        QLabel* lbl_sapore = new QLabel("Sapore: ", this);
        QLabel* lbl_target = new QLabel("Target: ", this);
        QLabel* lbl_applicazione = new QLabel("Applicazione: ", this);
        QLabel* lbl_profumazione = new QLabel("Profumazione: ", this);
        _fld_scadenza->setDate(QDate::currentDate().addDays(1));
        _fld_scadenza->setVisible(true);
        _fld_sapore->setVisible(true);
        _fld_target->setVisible(true);
        _fld_applicazione->setVisible(true);
        _fld_profumazione->setVisible(true);
        lout_form->addRow(lbl_scadenza, _fld_scadenza);
        lout_form->addRow(lbl_sapore, _fld_sapore);
        lout_form->addRow(lbl_target, _fld_target);
        lout_form->addRow(lbl_applicazione, _fld_applicazione);
        lout_form->addRow(lbl_profumazione, _fld_profumazione);
    }
    else
    { // tipo di prodotto non riconosciuto
        _fld_id->setValue(0);
        _fld_nome->setText("Errore");
        _fld_descrizione->setText("Errore");
        _fld_ditta->setText("Errore");
        _fld_costo->setValue(0);
        _fld_iva->setValue(0);
        _fld_nome->setEnabled(false);
        _fld_descrizione->setEnabled(false);
        _fld_ditta->setEnabled(false);
        _fld_costo->setEnabled(false);
        _fld_iva->setEnabled(false);
        btn_conferma->setEnabled(false);
    }

    lout_main->addLayout(lout_form);
    lout_main->addWidget(btn_conferma, Qt::AlignCenter);

    connect(btn_conferma, SIGNAL(clicked()), this, SLOT(istanziaProdotto()));
}

void insertWidget::istanziaProdotto()
{
    QMessageBox box;
    Prodotto* p = nullptr;
    if(_tipoProdotto == "Vivanda")
    {
        p = new Vivanda(static_cast<unsigned short>(_fld_id->value()),
                        _fld_nome->text().toStdString(),
                        _fld_descrizione->text().toStdString(),
                        _fld_costo->value(),
                        _fld_ditta->text().toStdString(),
                        _fld_iva->value(),
                        _fld_scadenza->text().toStdString(),
                        _fld_sapore->text().toStdString());
    }
    else if(_tipoProdotto == "Cosmetico")
    {
        p = new Cosmetico(static_cast<unsigned short>(_fld_id->value()),
                          _fld_nome->text().toStdString(),
                          _fld_descrizione->text().toStdString(),
                          _fld_costo->value(),
                          _fld_ditta->text().toStdString(),
                          _fld_iva->value(),
                          _fld_target->currentText().toStdString(),
                          _fld_applicazione->text().toStdString());
    }
    else if(_tipoProdotto == "Integratore")
    {
        p = new Integratore(static_cast<unsigned short>(_fld_id->value()),
                            _fld_nome->text().toStdString(),
                            _fld_descrizione->text().toStdString(),
                            _fld_costo->value(),
                            _fld_ditta->text().toStdString(),
                            _fld_iva->value(),
                            _fld_scadenza->text().toStdString(),
                            (_fld_dispositivoMedico->currentText() == "SI" ? true : false));
    }
    else if(_tipoProdotto == "Olio essenziale")
    {
        p = new OlioEssenziale(static_cast<unsigned short>(_fld_id->value()),
                               _fld_nome->text().toStdString(),
                               _fld_descrizione->text().toStdString(),
                               _fld_costo->value(),
                               _fld_ditta->text().toStdString(),
                               _fld_iva->value(),
                               _fld_scadenza->text().toStdString(),
                               _fld_sapore->text().toStdString(),
                               _fld_target->currentText().toStdString(),
                               _fld_applicazione->text().toStdString(),
                               _fld_profumazione->text().toStdString());
    }

    if(p)
    {
        _tablemodel->setNuovoElemento(p);
        _proxymodel->insertRows(_proxymodel->rowCount(), 1);
        _view->clearSelection();
        _view->selectionModel()->clearCurrentIndex();
        _view->selectionModel()->select(_proxymodel->index(_tablemodel->rowCount() - 1, 0), QItemSelectionModel::Select);
        delete _tablemodel->getNuovoElemento();
        box.setText("Inserimento effettuato con successo");
        box.exec();
    }
    else
    {
        box.setText("Inserimento fallito");
    }
    close();
}
