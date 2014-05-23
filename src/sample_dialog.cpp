#include "sample_dialog.h"
#include <QtGui/QtGui>

SampleDialog::SampleDialog( QWidget* pParent /*= NULL*/ )
    : QDialog(pParent)
{
    //////////////////////////////////////////////////////////////////////////
    ///  Create all the widgets on dialog
    //////////////////////////////////////////////////////////////////////////
    // A label with a edit box
    QLabel* pLabel = new QLabel(tr("Search &Text"));
    m_pLineEdit = new QLineEdit;
    pLabel->setBuddy(m_pLineEdit);

    // A check box
    m_pCaseCheckBox = new QCheckBox(tr("Match &Case"));

    // Search button and close button
    m_pSearchBtn = new QPushButton(tr("&Search"));
    m_pSearchBtn->setDefault(true);
    m_pSearchBtn->setEnabled(false);
    m_pCloseBtn = new QPushButton(tr("Close"));

    //////////////////////////////////////////////////////////////////////////
    ///  Layout the window
    //////////////////////////////////////////////////////////////////////////
    QHBoxLayout* pTopLeftLayout = new QHBoxLayout;
    pTopLeftLayout->addWidget(pLabel);
    pTopLeftLayout->addWidget(m_pLineEdit);

    QVBoxLayout* pLeftLayout = new QVBoxLayout;
    pLeftLayout->addLayout(pTopLeftLayout);
    pLeftLayout->addWidget(m_pCaseCheckBox);

    QVBoxLayout* pRightLayout = new QVBoxLayout;
    pRightLayout->addWidget(m_pSearchBtn);
    pRightLayout->addWidget(m_pCloseBtn);
    pRightLayout->addStretch();

    QHBoxLayout* pMainLayout = new QHBoxLayout;
    pMainLayout->addLayout(pLeftLayout);
    pMainLayout->addLayout(pRightLayout);

    //////////////////////////////////////////////////////////////////////////
    ///  Link signals and slots
    //////////////////////////////////////////////////////////////////////////
    connect(m_pLineEdit, SIGNAL(textChanged(const QString&)), 
            this, SLOT(enableSearchButtion(const QString&)));
    connect(m_pCloseBtn, SIGNAL(clicked()), 
            this, SLOT(close()));

    setLayout(pMainLayout);
}

void SampleDialog::enableSearchButtion( const QString& text )
{
    m_pSearchBtn->setEnabled(!text.isEmpty());
}
