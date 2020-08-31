#ifndef DELEGATE_H
#define DELEGATE_H

#include <QStyledItemDelegate>
class QString;
class QSpinBox;
class QDoubleSpinBox;
class QLineEdit;
class QComboBox;
class Prodotto;

class Delegate: public QStyledItemDelegate
{
    Q_OBJECT
public:
    using QStyledItemDelegate::QStyledItemDelegate;

    QWidget* createEditor(QWidget *parent, const QStyleOptionViewItem &option,
                          const QModelIndex &index) const override;

    void setEditorData(QWidget* editor, const QModelIndex& index) const override;
    void setModelData(QWidget* editor, QAbstractItemModel* model,
                      const QModelIndex &index) const override;

    void updateEditorGeometry(QWidget* editor, const QStyleOptionViewItem &option,
                           const QModelIndex &index) const override;
private slots:
    void commitAndCloseEditor();

};
#endif // DELEGATE_H
