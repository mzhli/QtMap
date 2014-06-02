#include <QtGui/QtGui>
#include "sample_mainwindow.h"
#include "sort_dialog.h"


MainWindow::MainWindow()
{
    m_pSpreadsheet = new QTableWidget;
    setCentralWidget(m_pSpreadsheet);

    CreateActions();
    CreateMenus();
    CreateContextMenu();
    CreateToolBars();
    CreateStatusBar();

    ReadSettings();

    setWindowIcon(QIcon(":/images/16x16/Shield.png"));
    SetCurrentFile("");
}

void MainWindow::CreateActions()
{
    m_pNewAction = new QAction(tr("&New"), this);
    m_pNewAction->setIcon(QIcon(":/images/16x16/New document.png"));
    m_pNewAction->setShortcut(QKeySequence::New);
    m_pNewAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(m_pNewAction, SIGNAL(triggered()), this, SLOT(newFile()));

    m_pOpenAction = new QAction(tr("&Open"), this);
    m_pOpenAction->setIcon(QIcon(":/images/16x16/Play.png"));
    m_pOpenAction->setShortcut(QKeySequence::Open);
    m_pOpenAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(m_pOpenAction, SIGNAL(triggered()), this, SLOT(open()));

    m_pAboutAction = new QAction(tr("&About QtMap"), this);
    m_pAboutAction->setStatusTip(tr("Show the QtMap's about box"));
    connect(m_pAboutAction, SIGNAL(triggered()), this, SLOT(about()));

    for (int i = 0; i < MAX_RECENT_FILES; i++)
    {
        m_recentFileActions[i] = new QAction(this);
        m_recentFileActions[i]->setVisible(false);
        connect(m_recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }

    m_pExitAction = new QAction(tr("E&xit"), this);
    m_pExitAction->setIcon(QIcon(":/images/16x16/Exit.png"));
    m_pExitAction->setShortcut(tr("Ctrl+Q"));
    m_pExitAction->setStatusTip(tr("Exit the application"));
    connect(m_pExitAction, SIGNAL(triggered()), this, SLOT(close()));
}

void MainWindow::CreateMenus()
{
    m_pFileMenu = menuBar()->addMenu(tr("&File"));
    m_pFileMenu->addAction(m_pNewAction);
    m_pFileMenu->addAction(m_pOpenAction);
    m_pSeparateAction = m_pFileMenu->addSeparator();
    for (int i = 0; i < MAX_RECENT_FILES; i++)
    {
        m_pFileMenu->addAction(m_recentFileActions[i]);
    }
    m_pFileMenu->addSeparator();
    m_pFileMenu->addAction(m_pExitAction);
}

void MainWindow::CreateContextMenu()
{

}

void MainWindow::CreateStatusBar()
{

}

void MainWindow::ReadSettings()
{

}

void MainWindow::WriteSettings()
{

}

bool MainWindow::OkToContinue()
{
    return true;
}

bool MainWindow::LoadFile( const QString& filename )
{
    return true;
}

bool MainWindow::SaveFile( const QString& filename )
{
    return true;
}

void MainWindow::SetCurrentFile( const QString& filename )
{

}

void MainWindow::UpdateRecentFileActions()
{

}

QString MainWindow::StrippedName( const QString& fullFileName )
{
    return QString("");
}

void MainWindow::newFile()
{

}

void MainWindow::open()
{

}

bool MainWindow::save()
{
    return true;
}

bool MainWindow::saveAs()
{
    return true;
}

void MainWindow::find()
{

}

void MainWindow::sort()
{

}

void MainWindow::about()
{

}

void MainWindow::openRecentFile()
{

}

void MainWindow::updateStatusBar()
{

}

void MainWindow::spreadsheetModifed()
{

}

void MainWindow::closeEvent( QCloseEvent* event )
{

}

void MainWindow::CreateToolBars()
{

}




