#ifndef _QTMAP_STATECITYINPUT_DIALOG_H_
#define _QTMAP_STATECITYINPUT_DIALOG_H_
#include <QDialog>
#include "ui_statecityinput.h"

/**
 * A dialog derived from ui file
 */
class StateCityInputDialog : public QDialog, public Ui::StateCityInputDialog
{
    Q_OBJECT
public:
    StateCityInputDialog(QWidget* pParent = NULL);

private slots:
    void on_lineEdit_textChanged();
};

#endif