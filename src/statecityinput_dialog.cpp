#include "statecityinput_dialog.h"
#include <QtGui>

StateCityInputDialog::StateCityInputDialog( QWidget* pParent /*= NULL*/ )
    : QDialog(pParent)
{
    setupUi(this);
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(false);

    QRegExp regExp("[a-zA-Z]{5,10}");
    lineEdit->setValidator(new QRegExpValidator(regExp, this));
    
    connect(buttonBox, SIGNAL(accepted()), this, SLOT(accept()));
    connect(buttonBox, SIGNAL(rejected()), this, SLOT(reject()));
}

void StateCityInputDialog::on_lineEdit_textChanged()
{
    buttonBox->button(QDialogButtonBox::Ok)->setEnabled(lineEdit->hasAcceptableInput());
}
