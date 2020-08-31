//#include <QtWidgets>
//#include "Modello/Gerarchia/prodotto.h"
//#include "Modello/Gerarchia/cosmetico.h"
//#include "listmodeladapter.h"
////#include "delegate.h"
////#include "editor.h"
//#include "qtypeconversion.h"
//#include <QLineEdit>
//#include <QLabel>
//#include <QComboBox>
//#include <QSpinBox>
//#include <QDoubleSpinBox>
//#include <QVBoxLayout>
//#include <QHBoxLayout>
//#include <QFormLayout>
//#include <QString>
//#include "qfilterproxymodel.h"

////QWidget* Delegate::createEditor(QWidget *parent,
////                                const QStyleOptionViewItem &option,
////                                const QModelIndex &index) const
////{
//////   QWidget* editor= new MyEditor(parent);
////   connect(editor, SIGNAL(editingFinished()),
////            this, SLOT(commitAndCloseEditor()));
////    return editor;
////}

//void Delegate::setEditorData(QWidget *editor, const QModelIndex &index) const
//{
//    MyEditor* edt= static_cast<MyEditor*>(editor);
//     membroSocieta* val=
//            (index.model()->data(index, Qt::EditRole)).value<membroSocieta*>();

//    edt->c1->setCurrentText(val->isContrattoScaduto() ? "scaduto" : "valido");
//    if(val->getType() == "Dirigente")
//    {
//        editor->setGeometry(200, 150, 200, 100);
//        editor->setFixedSize(200, 100);
//        edt->l2->setVisible(false);
//        edt->l3->setVisible(false);
//        edt->c2->setVisible(false);
//        edt->box->setVisible(false);
//    }
//    else if(val->getType() == "Allenatore")
//    {
//        editor->setGeometry(200, 150, 250, 150);
//        editor->setFixedSize(250, 200);
//        edt->l3->setVisible(false);
//        edt->box->setVisible(false);
//        edt->c2->setCurrentText(
//           static_cast<Allenatore*>(val)->
//                    getMinObiettiviStagionali()?"raggiunti" : "non raggiunti");
//    }
//    else if(val->getType() == "Calciatore")
//    {
//        editor->setGeometry(200, 150, 200, 150);
//        editor->setFixedSize(200, 150);
//        edt->l2->setVisible(false);
//        edt->c2->setVisible(false);
//        edt->box->setValue(
//           static_cast<Calciatore*>(val)->getPresenze());
//    }

//}

//void Delegate::setModelData(QWidget *editor, QAbstractItemModel *model, const QModelIndex &index) const
//{
//    MyEditor* edt= static_cast<MyEditor*>(editor);

//    membroSocieta* val=
//            (index.model()->data(index, Qt::EditRole)).value<membroSocieta*>();

//    bool c= (edt->c1->currentText() == "valido");
//    bool minObb=false;
//    unsigned int p=0;
//    if(val->getType() == "Allenatore")
//        minObb= (edt->c2->currentText() == "raggiunti");

//    else if(val->getType() == "Calciatore")
//        p= static_cast<unsigned int>(edt->box->value());

//   static_cast<ListModelAdapter*>(
//     static_cast<QFilterProxyModel*>(model)->sourceModel())
//       ->mySetData(index, QString::fromStdString(val->getType()), c, minObb, p);
//}

//void Delegate::updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option,
//                          const QModelIndex &index) const
//{
//    editor->setGeometry(option.rect);
//}

//void Delegate::commitAndCloseEditor()
//{
//    //sender() restituisce l'indirizzo dell'oggetto (il mio editor in questo
//    //caso) che ha mandato il segnale che ha innescato questo slot
//    MyEditor* editor= qobject_cast<MyEditor*> (sender());
//    emit commitData(editor);
//    emit closeEditor(editor);
//}
