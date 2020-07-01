#ifndef INSERTIONWIDGET_H
#define INSERTIONWIDGET_H

#include <QDialog>
#include <QLabel>
#include <QVBoxLayout>
#include <QFormLayout>
#include <QLineEdit>
#include <QDoubleSpinBox>
#include <QPushButton>

class insertionWidget : public QDialog {
private:
    QDoubleSpinBox* id_fld;
    QLineEdit* nome_fld;
    QLineEdit* descrizione_fld;
    QLineEdit* ditta_fld;
    QDoubleSpinBox* costo_fld;
    QDoubleSpinBox* iva_fld;
public:
    insertionWidget();
};

#endif // INSERTIONWIDGET_H
