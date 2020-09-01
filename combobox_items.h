#ifndef COMBOBOX_ITEMS_H
#define COMBOBOX_ITEMS_H

#include <QComboBox>

class combobox_items : public QComboBox
{
    Q_OBJECT
public:
    combobox_items(QWidget* = nullptr, QString = "");
};

#endif // COMBOBOX_ITEMS_H
