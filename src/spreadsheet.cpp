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

void Spreadsheet::clear()
{
    setRowCount(0);
    setColumnCount(0);
    setRowCount(RowCount);
    setColumnCount(ColumnCount);

    for (int i = 0; i < ColumnCount; i++)
    {
        QTableWidgetItem* pItem = new QTableWidgetItem;
        pItem->setText(QString('A' + i));
        setHorizontalHeaderItem(i, pItem);
    }

    setCurrentCell(0, 0);
}

Cell* Spreadsheet::cell( int row, int column ) const
{
    return static_cast<Cell*>(item(row, column));
}

QString Spreadsheet::text( int row, int column ) const
{
    Cell* pCell = cell(row, column);
    if (pCell != NULL)
    {
        return pCell->text();
    }
    else
    {
        return "";
    }
}

QString Spreadsheet::currentLocation() const
{
    return QChar('A' + currentColumn()) + QString::number(currentRow() + 1);
}

void Spreadsheet::somethingChanged()
{
    emit modified();
}

bool Spreadsheet::writeFile( const QString& strFileName )
{
    // Open a new file for writing
    QFile file(strFileName);
    if (! file.open(QIODevice::WriteOnly))
    {
        QMessageBox::warning(this, tr("Spreadsheet"), 
                             tr("Cannot write file %1:\n%2.").arg(file.fileName(), file.errorString()));
        return false;
    }

    // Init a output stream
    QDataStream out(&file);
    out.setVersion(QDataStream::Qt_4_8);
    out << (quint32)MagicNumber;

    // Write cell one by one
    QApplication::setOverrideCursor(Qt::WaitCursor);
    for (int row = 0; row < RowCount; row++)
    {
        for (int col = 0; col < ColumnCount; col++)
        {
            QString strCellText = text(row, col);
            if (! strCellText.isEmpty())
            {
                out << (quint16)row << (quint16)col << strCellText;
            }
        }
    }
    QApplication::restoreOverrideCursor();
    return true;
}

bool Spreadsheet::readFile( const QString& strFileName )
{
    // Open file for reading
    QFile file(strFileName);
    if (! file.open(QIODevice::ReadOnly))
    {
        QMessageBox::warning(this, tr("Spreadsheet"),
                             tr("Cannot read file %1:\n%2").arg(file.fileName(), file.errorString()));
        return false;
    }

    // Create stream with the correct version
    QDataStream in(&file);
    in.setVersion(QDataStream::Qt_4_8);

    // Check the magic number see if the file is a spreadsheet file
    quint32 nMagicNumber;
    in >> nMagicNumber;
    if (nMagicNumber != MagicNumber)
    {
        QMessageBox::warning(this, tr("Spreadsheet"),
                             tr("The file is not a Spreadsheet file"));
        return false;
    }

    // Clear current spreadsheet and load every cell from file
    clear();

    quint16 row;
    quint16 col;
    QString strCellText;

    QApplication::setOverrideCursor(Qt::WaitCursor);
    while (! in.atEnd())
    {
        in >> row >> col >> strCellText;
        // Validate row and col read in case of problem
        if (row < RowCount && col < ColumnCount)
        {
            Cell* pCell = cell(row, col);
            if (NULL == pCell)
            {
                pCell = new Cell;
                setItem(row, col, pCell);
            }
            pCell->setText(strCellText);
        }
    }
    QApplication::restoreOverrideCursor();
    return true;
}

QTableWidgetSelectionRange Spreadsheet::selectedRange() const
{
    QList<QTableWidgetSelectionRange> ranges = selectedRanges();
    if (ranges.isEmpty())
    {
        return QTableWidgetSelectionRange();
    }
    else
    {
        return ranges.first();
    }
}

void Spreadsheet::cut()
{

}

void Spreadsheet::copy()
{

}

void Spreadsheet::paste()
{

}

void Spreadsheet::del()
{

}

void Spreadsheet::selectCurrentRow()
{
    selectRow(currentRow());
}

void Spreadsheet::selectCurrentColumn()
{
    selectColumn(currentColumn());
}

