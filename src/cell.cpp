#include <QtGui/QtGui>
#include "cell.h"


Cell::Cell()
{
    setDirty();
}

QTableWidgetItem* Cell::clone() const
{
    return new Cell(*this);
}

void Cell::setData( int role, const QVariant& val )
{
    QTableWidgetItem::setData(role, val);
    if (Qt::EditRole == role)
    {
        setDirty();
    }
}

void Cell::setDirty()
{
    cacheIsDirty = true;
}

QVariant Cell::data( int role ) const
{
    if (role == Qt::DisplayRole)
    {
        if (value().isValid())
        {
            return value().toString();
        }
        else
        {
            return "####";
        }
    }
    else if (role == Qt::TextAlignmentRole)
    {
        if (value().type() == QVariant::String)
        {
            return (int)(Qt::AlignLeft | Qt::AlignVCenter);
        }
        else
        {
            return (int)(Qt::AlignRight | Qt::AlignVCenter);
        }
    }
    else
    {
        return QTableWidgetItem::data(role);
    }
}

QVariant Cell::value() const
{
    if (cacheIsDirty)
    {
        cacheIsDirty = false;
        QString val = QTableWidgetItem::data(Qt::EditRole).toString();
        bool bIsDouble = false;
        double dbl = val.toDouble(&bIsDouble);
        if (bIsDouble)
        {
            cachedValue = dbl;
        }
        else
        {
            cachedValue = val;
        }
    }
    return cachedValue;
}
