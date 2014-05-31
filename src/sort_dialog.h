#ifndef _QTMAP_SORT_DIALOG_H_
#define _QTMAP_SORT_DIALOG_H_
#include <QDialog>

#include "ui_sort.h"

/**
 * A dialog which demonstrate the extensible dialog
 */
class SortDialog : public QDialog, public Ui::SortDialog
{
    Q_OBJECT
public:
    SortDialog(QWidget* pParent = NULL);

    void SetColumnRange(QChar first, QChar last);
};

#endif  // _QTMAP_SORT_DIALOG_H_
