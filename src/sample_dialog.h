#ifndef _QTMAP_SAMPLE_DIALOG_H_
#define _QTMAP_SAMPLE_DIALOG_H_
#include <QDialog>

class QLineEdit;
class QCheckBox;
class QPushButton;
class QLabel;

/**
 * A sample dialog demo
 */
class SampleDialog : public QDialog
{
    Q_OBJECT
public:
    SampleDialog(QWidget* pParent = NULL);

public slots:
    void enableSearchButtion(const QString& text);

private:
    QLineEdit* m_pLineEdit;
    QCheckBox* m_pCaseCheckBox;
    QPushButton* m_pSearchBtn;
    QPushButton* m_pCloseBtn;
};

#endif  // _QTMAP_SAMPLE_DIALOG_H_
