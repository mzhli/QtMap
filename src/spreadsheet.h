#ifndef _QTMAP_SPREAD_SHEET_H_
#define _QTMAP_SPREAD_SHEET_H_

#include <QTableWidget>

class Cell;
class SpreadsheetCompare;

class Spreadsheet : public QTableWidget
{
    Q_OBJECT
public:
    Spreadsheet(QWidget* pParent = NULL);

    QString currentLocation() const;
    QString currentFormula() const;
    QTableWidgetSelectionRange selectedRange() const;
    void clear();
    bool readFile(const QString& strFileName);
    bool writeFile(const QString& strFileName);
    void sort(const SpreadsheetCompare& comp);

public slots:
    void cut();
    void copy();
    void paste();
    void del();
    void selectCurrentRow();
    void selectCurrentColumn();

public signals:
    void modified();

private slots:
    void somethingChanged();

private:
    enum 
    { 
        MagicNumber = 0x7F51C883,
        RowCount = 999,
        ColumnCount = 26
    };

    Cell* cell(int row, int column) const;
    QString text(int row, int column) const;
};

class SpreadsheetCompare
{
public:
    bool operator () (const QStringList& row1, const QStringList& row2) const;
    enum { KeyCount = 3 };
    int keys[KeyCount];
    bool ascending[KeyCount];
};

#endif  // _QTMAP_SPREAD_SHEET_H_
