#ifndef _QTMAP_SAMPLE_MAINWINDOW_H_
#define _QTMAP_SAMPLE_MAINWINDOW_H_

#include <QMainWindow>

class QAction;
class QTableWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT
public:
    MainWindow();

protected:
    void closeEvent(QCloseEvent* event);

private slots:
    void newFile();
    void open();
    bool save();
    bool saveAs();
    void copy();
    void cut();
    void paste();
    void find();
    void sort();
    void about();
    void openRecentFile();
    void updateStatusBar();
    void spreadsheetModifed();

private:
    void CreateActions();
    void CreateMenus();
    void CreateContextMenu();
    void CreateToolBars();
    void CreateStatusBar();
    void ReadSettings();
    void WriteSettings();
    bool OkToContinue();
    bool LoadFile(const QString& filename);
    bool SaveFile(const QString& filename);
    void SetCurrentFile(const QString& filename);
    void UpdateRecentFileActions();
    QString StrippedName(const QString& fullFileName);

    QTableWidget* m_pSpreadsheet;
    QStringList m_recentFiles;
    QString m_curFile;
    
    enum { MAX_RECENT_FILES = 5 };
    QAction* m_recentFileActions[MAX_RECENT_FILES];
    QAction* m_pSeparateAction;
    QAction* m_pNewAction;
    QAction* m_pOpenAction;
    QAction* m_pSaveAction;
    QAction* m_pSaveAsAction;
    QAction* m_pExitAction;

    QAction* m_pCopyAction;
    QAction* m_pCutAction;
    QAction* m_pPasteAction;
    QAction* m_pFindAction;

    QAction* m_pSortAction;

    QAction* m_pAboutAction;

    QMenu* m_pFileMenu;
    QMenu* m_pEditMenu;
    QMenu* m_pToolsMenu;
    QMenu* m_pOptionsMenu;
    QMenu* m_pHelpMenu;

    QToolBar* m_pFileToolBar;
    QToolBar* m_pEditToolBar;
};

#endif  // _QTMAP_SAMPLE_MAINWINDOW_H_
