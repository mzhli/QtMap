#include "sort_dialog.h"
#include <QtGui/QtGui>

SortDialog::SortDialog( QWidget* pParent /*= NULL*/ )
    : QDialog(pParent)
{
    setupUi(this);
    secondGroupBox->hide();
    thirdGroupBox->hide();
    layout()->setSizeConstraint(QLayout::SetFixedSize);

    firstOrderCombo->addItem(tr("Asc"));
    firstOrderCombo->addItem(tr("Desc"));
    secondOrderCombo->addItem(tr("Asc"));
    secondOrderCombo->addItem(tr("Desc"));
    thirdOrderCombo->addItem(tr("Asc"));
    thirdOrderCombo->addItem(tr("Desc"));
    SetColumnRange('A', 'Z');
}

void SortDialog::SetColumnRange( QChar first, QChar last )
{
    firstColumnCombo->clear();
    secondColumnCombo->clear();
    thirdColumnCombo->clear();

    secondColumnCombo->addItem(tr("None"));
    thirdColumnCombo->addItem(tr("None"));
    firstColumnCombo->setMinimumSize(secondColumnCombo->sizeHint());

    QChar c = first;
    while (c <= last)
    {
        firstColumnCombo->addItem(QString(c));
        secondColumnCombo->addItem(QString(c));
        thirdColumnCombo->addItem(QString(c));
        c = c.unicode() + 1;
    }
}
