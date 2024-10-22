#include "qfilterproxymodel.h"
#include "tablemodeladapter.h"

QFilterProxyModel::QFilterProxyModel(QObject* parent, const QString& filter)
    : QSortFilterProxyModel (parent), _filter(filter)
{}

bool QFilterProxyModel::insertRows(int begin, int count, const QModelIndex& parent)
{
    bool result = sourceModel()->insertRows(begin, count, parent);
    invalidateFilter();
    return result;
}

bool QFilterProxyModel::filterAcceptsRow(int row_source, const QModelIndex&) const
{
    return (static_cast<const TableModelAdapter*>(sourceModel()))->matchFiltersSelected(static_cast<unsigned int>(row_source), filterRegExp(), _filter);
}

void QFilterProxyModel::setFilter(const QString& text)
{
    _filter = text;
}
