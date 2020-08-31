#include <QtWidgets>
#include "Modello/Gerarchia/prodotto.h"
#include "Modello/Gerarchia/alimentare.h"
#include "Modello/Gerarchia/cosmetico.h"
#include "Modello/Gerarchia/vivanda.h"
#include "Modello/Gerarchia/integratore.h"
#include "Modello/Gerarchia/olioEssenziale.h"
#include "listmodeladapter.h"
#include "delegate.h"
#include "editor.h"
#include "qtypeconversion.h"
#include <QLineEdit>
#include <QLabel>
#include <QComboBox>
#include <QSpinBox>
#include <QDoubleSpinBox>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <QFormLayout>
#include <QString>
#include "qfilterproxymodel.h"

QWidget* Delegate::createEditor(QWidget *parent,
                                const QStyleOptionViewItem &option,
                                const QModelIndex &index) const
{
   QWidget* editor = new MyEditor(parent);
   connect(editor, SIGNAL(editingFinished()),
            this, SLOT(commitAndCloseEditor()));
    return editor;
}

void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
{
    MyEditor* edt = static_cast<MyEditor*>(editor);
     Prodotto* val=
            (index.model()->data(index, Qt::EditRole)).value<Prodotto*>();

    edt->c1->setCurrentText("riga 37 delegate");
    if(val->getTipo() == "Cosmetico")
    {
        editor->setGeometry(200, 150, 200, 100);
        editor->setFixedSize(200, 100);
        edt->l2->setVisible(false);
        edt->l3->setVisible(false);
        edt->c2->setVisible(false);
        edt->box->setVisible(false);
    }
    else if(val->getTipo() == "Vivanda")
    {
        editor->setGeometry(200, 150, 250, 150);
        editor->setFixedSize(250, 200);
        edt->l3->setVisible(false);
        edt->box->setVisible(false);
        edt->c2->setCurrentText("riga 53 delegate");
    }
    else if(val->getTipo() == "Integratore")
    {
        editor->setGeometry(200, 150, 200, 150);
        editor->setFixedSize(200, 150);
        edt->l2->setVisible(false);
        edt->c2->setVisible(false);
        edt->box->setValue(99);
    }

}

void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
{
    MyEditor* edt= static_cast<MyEditor*>(editor);

    Prodotto* val=
            (index.model()->data(index, Qt::EditRole)).value<Prodotto*>();

    bool c = (edt->c1->currentText() == "valido");
    bool minObb = false;
    unsigned int p=0;
    if(val->getTipo() == "Cosmetico")
        minObb = (edt->c2->currentText() == "raggiunti");

    else if(val->getTipo() == "Vivanda")
        p = static_cast<unsigned int>(edt->box->value());

   static_cast<ListModelAdapter*>(
     static_cast<QFilterProxyModel*>(model)->sourceModel())
       ->mySetData(index, QString::fromStdString(val->getTipo()), c, minObb, p);
}

void Delegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const
{
    editor->setGeometry(option.rect);
}

void Delegate::commitAndCloseEditor()
{
    //sender() restituisce l'indirizzo dell'oggetto (il mio editor in questo
    //caso) che ha mandato il segnale che ha innescato questo slot
    MyEditor* editor= qobject_cast<MyEditor*> (sender());
    emit commitData(editor);
    emit closeEditor(editor);
}
