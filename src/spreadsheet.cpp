#include <QtGui/QtGui>

#include "cell.h"
#include "spreadsheet.h"


Spreadsheet::Spreadsheet( QWidget* pParent /*= NULL*/ )
    : QTableWidget(pParent)
{
    setItemPrototype(new Cell);
    setSelectionMode(QAbstractItemView::ContiguousSelection);

    connect(this, SIGNAL(itemChanged(QTableWidgetItem*)), this, SLOT(somethingChanged()));

    clear();
}
