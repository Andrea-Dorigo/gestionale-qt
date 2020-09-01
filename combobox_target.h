#ifndef COMBOBOX_TARGET_H
#define COMBOBOX_TARGET_H

#include <QComboBox>

class combobox_target : public QComboBox
{
    Q_OBJECT
public:
    combobox_target(QWidget* = nullptr);
};

#endif // COMBOBOX_TARGET_H
