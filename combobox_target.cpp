#include "combobox_target.h"

combobox_target::combobox_target(QWidget* parent):
    QComboBox (parent)
{
    addItem("UNISEX");
    addItem("UOMO");
    addItem("DONNA");
}
