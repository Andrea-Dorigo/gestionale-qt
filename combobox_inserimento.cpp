#include "combobox_inserimento.h"

combobox_inserimento::combobox_inserimento(QWidget* parent):
    QComboBox (parent)
{
    addItem("Inserisci");
    addItem("Cosmetico");
    addItem("Vivanda");
    addItem("Integratore");
    addItem("Olio essenziale");
}
