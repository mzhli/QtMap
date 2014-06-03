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
    // "New"
    m_pNewAction = new QAction(tr("&New"), this);
    m_pNewAction->setIcon(QIcon(":/images/16x16/New document.png"));
    m_pNewAction->setShortcut(QKeySequence::New);
    m_pNewAction->setStatusTip(tr("Create a new spreadsheet file"));
    connect(m_pNewAction, SIGNAL(triggered()), this, SLOT(newFile()));

    // "Open"
    m_pOpenAction = new QAction(tr("&Open"), this);
    m_pOpenAction->setIcon(QIcon(":/images/16x16/Play.png"));
    m_pOpenAction->setShortcut(QKeySequence::Open);
    m_pOpenAction->setStatusTip(tr("Open an existing spreadsheet file"));
    connect(m_pOpenAction, SIGNAL(triggered()), this, SLOT(open()));

    // "Recent Files"
    for (int i = 0; i < MAX_RECENT_FILES; i++)
    {
        m_recentFileActions[i] = new QAction(this);
        m_recentFileActions[i]->setVisible(false);
        connect(m_recentFileActions[i], SIGNAL(triggered()), this, SLOT(openRecentFile()));
    }

    // "Exit"
    m_pExitAction = new QAction(tr("E&xit"), this);
    m_pExitAction->setIcon(QIcon(":/images/16x16/Exit.png"));
    m_pExitAction->setShortcut(tr("Ctrl+Q"));
    m_pExitAction->setStatusTip(tr("Exit the application"));
    connect(m_pExitAction, SIGNAL(triggered()), this, SLOT(close()));

    // "Copy"
    m_pCopyAction = new QAction(tr("&Copy"), this);
    m_pCopyAction->setIcon(QIcon(":/images/16x16/Copy.png"));
    m_pCopyAction->setShortcut(QKeySequence::Copy);
    m_pCopyAction->setStatusTip(tr("Copy the selected area into clipboard"));
    connect(m_pCopyAction, SIGNAL(triggered()), this, SLOT(copy()));

    // "Cut"
    m_pCutAction = new QAction(tr("Cu&t"), this);
    m_pCutAction->setIcon(QIcon(":/images/16x16/Cut.png"));
    m_pCutAction->setShortcut(QKeySequence::Cut);
    m_pCutAction->setStatusTip(tr("Cut the selected area into clipboard"));
    connect(m_pCutAction, SIGNAL(triggered()), this, SLOT(cut()));

    // "Paste"
    m_pPasteAction = new QAction(tr("&Paste"), this);
    m_pPasteAction->setIcon(QIcon(":/images/16x16/Paste.png"));
    m_pPasteAction->setShortcut(QKeySequence::Paste);
    m_pPasteAction->setStatusTip(tr("Paste the content in clipboard into current position"));
    connect(m_pPasteAction, SIGNAL(triggered()), this, SLOT(paste()));

    // "Find"
    m_pFindAction = new QAction(tr("&Find"), this);
    m_pFindAction->setIcon(QIcon(":/images/16x16/Find.png"));
    m_pFindAction->setShortcut(QKeySequence::Find);
    m_pFindAction->setStatusTip(tr("Find content"));
    connect(m_pFindAction, SIGNAL(triggered()), this, SLOT(find()));

    // "Sort..."
    m_pSortAction = new QAction(tr("&Sort..."), this);
    m_pSortAction->setIcon(QIcon(":/images/16x16/Sort.png"));
    connect(m_pSortAction, SIGNAL(triggered()), this, SLOT(sort()));

    // "About QtMap"
    m_pAboutAction = new QAction(tr("About Qt&Map"), this);
    m_pAboutAction->setIcon(QIcon(":/images/16x16/Help symbol.png"));
    m_pAboutAction->setStatusTip(tr("Show the QtMap's about box"));
    connect(m_pAboutAction, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::CreateMenus()
{
    // File menu
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

    // Edit menu
    m_pEditMenu = menuBar()->addMenu(tr("&Edit"));
    m_pEditMenu->addAction(m_pCutAction);
    m_pEditMenu->addAction(m_pCopyAction);
    m_pEditMenu->addAction(m_pPasteAction);
    m_pEditMenu->addSeparator();
    m_pEditMenu->addAction(m_pFindAction);

    // Tools menu
    m_pToolsMenu = menuBar()->addMenu(tr("&Tools"));
    m_pToolsMenu->addAction(m_pSortAction);

    // Help menu
    m_pHelpMenu = menuBar()->addMenu(tr("&Help"));
    m_pHelpMenu->addAction(m_pAboutAction);
}

void MainWindow::CreateContextMenu()
{
    m_pSpreadsheet->addAction(m_pCutAction);
    m_pSpreadsheet->addAction(m_pCopyAction);
    m_pSpreadsheet->addAction(m_pPasteAction);
    m_pSpreadsheet->setContextMenuPolicy(Qt::ActionsContextMenu);
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

void MainWindow::copy()
{

}

void MainWindow::cut()
{

}

void MainWindow::paste()
{

}




