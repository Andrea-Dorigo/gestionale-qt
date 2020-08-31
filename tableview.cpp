#include "tableview.h"

TableView::TableView(QWidget* parent) : QTableView(parent) {

}
QSize TableView::sizeHint() const {
    return QSize(700, 800);
}
