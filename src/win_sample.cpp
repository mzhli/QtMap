#include "win_sample.h"
#include <QtGui/QtGui>
#include "sample_dialog.h"
#include "statecityinput_dialog.h"
#include "sort_dialog.h"
#include "sample_mainwindow.h"

int sample_label( int argc, char* argv[] )
{
    QApplication app(argc, argv);
    QLabel* pLabel = new QLabel("<h2><i>Hello <font color=red>Qt</font>!</i></h2>");
    pLabel->show();

    return app.exec();
}

int sample_layout( int argc, char* argv[] )
{
    QApplication app(argc, argv);
    QWidget* pMainWin = new QWidget;

    QSlider* pSlider = new QSlider(Qt::Horizontal);
    QSpinBox* pSpinBox = new QSpinBox;
    pSlider->setRange(0, 100);
    pSpinBox->setRange(0, 100);

    QObject::connect(pSlider, SIGNAL(valueChanged(int)),
                     pSpinBox, SLOT(setValue(int)));
    QObject::connect(pSpinBox, SIGNAL(valueChanged(int)),
                     pSlider, SLOT(setValue(int)));
    pSpinBox->setValue(30);

    QHBoxLayout* pLayout = new QHBoxLayout;
    pLayout->addWidget(pSlider);
    pLayout->addWidget(pSpinBox);
    pMainWin->setLayout(pLayout);
    pMainWin->show();

    return app.exec();
}

int sample_dialog( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    SampleDialog* pDialog = new SampleDialog;
    pDialog->setFixedSize(400, 100);
    pDialog->show();
    
    return app.exec();
}

int sample_ui_dialog( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    StateCityInputDialog* pDialog = new StateCityInputDialog();
    pDialog->show();

    return app.exec();
}

int sample_extensible_dialog( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    SortDialog* pDialog = new SortDialog();
    pDialog->show();

    return app.exec();
}

int sampel_mainwindow( int argc, char* argv[] )
{
    QApplication app(argc, argv);

    MainWindow* pWindow = new MainWindow();
    pWindow->show();

    return app.exec();
}
