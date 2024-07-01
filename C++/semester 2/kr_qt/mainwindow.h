#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>

class ChartWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;

private slots:
    void onActionOpenTriggered();
    void onActionSaveTriggered();
    void onActionSaveAsTriggered();
    void onActionCloseTriggered();
    void onActionExitTriggered();
    void onActionPenColorTriggered();
    void onActionPenStyleTriggered();
    void onActionBrushColorTriggered();
    void onActionAboutTriggered();

private:
    void createActions();
    void createMenus();
    void createContextMenu();
    void updateStatusBar();
    void loadData(const QString &fileName);
    void saveData(const QString &fileName);
    bool maybeSave();

    ChartWidget *chartWidget;
    QString currentFile;

    QAction *actionOpen;
    QAction *actionSave;
    QAction *actionSaveAs;
    QAction *actionClose;
    QAction *actionExit;
    QAction *actionPenColor;
    QAction *actionPenStyle;
    QAction *actionBrushColor;
    QAction *actionAbout;
};

#endif // MAINWINDOW_H
