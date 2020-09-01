#include "tableview.h"
#include <QHeaderView>

TableView::TableView(QWidget* parent) : QTableView(parent) {
    this->verticalHeader()->hide();
    this->verticalHeader()->setDefaultSectionSize(50);
    this->setSelectionBehavior(QAbstractItemView::SelectRows);
}
QSize TableView::sizeHint() const {
    return QSize(1200, 800);
}
/* overrides default behaviour and handles the double click event as a single click event*/
void TableView::mouseDoubleClickEvent(QMouseEvent* event) {
    QTableView::mousePressEvent(event);
}
