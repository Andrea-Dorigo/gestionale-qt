#include "combobox_items.h"

combobox_items::combobox_items(QWidget* parent, QString first):
    QComboBox (parent)
{
    addItem(first); // Inserisci (inserimento) || Nessuno (filtro)
    addItem("Cosmetico");
    addItem("Vivanda");
    addItem("Integratore");
    addItem("Olio essenziale");
}
