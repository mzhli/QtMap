#ifndef _QTMAP_CELL_H_
#define _QTMAP_CELL_H_

#include <QTableWidgetItem>

class Cell : public QTableWidgetItem
{
public:
    Cell();

    QTableWidgetItem* clone() const;
    void setData(int role, const QVariant& val);
    QVariant data(int role) const;
    void setDirty();

private:
    QVariant value() const;

    mutable QVariant cachedValue;
    mutable bool cacheIsDirty;
};

#endif
