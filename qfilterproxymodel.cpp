#include "qfilterproxymodel.h"

QFilterProxyModel::QFilterProxyModel(QObject* parent, const QString& f) :
    QSortFilterProxyModel (parent), filter(f) {}

bool QFilterProxyModel::insertRows(int begin, int count, const QModelIndex& parent)
{
    bool result = sourceModel()->insertRows(begin, count, parent);
    invalidateFilter();
    return result;
}

bool QFilterProxyModel::filterAcceptsRow(int row_source, const QModelIndex&) const
{
    return (static_cast<const ListModelAdapter*>(sourceModel()))->matchFiltersSelected(static_cast<unsigned int>(row_source), filterRegExp(), filter);
}

void QFilterProxyModel::setFilter(const QString& text)
{
    filter= text;
}
