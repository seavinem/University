#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QListWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_leftToRightButton_clicked();

    void on_rightToLeftButton_clicked();

    void on_editButton_clicked();

    void on_addLeftButton_clicked();

    void on_addRightButton_clicked();

    void on_addAllButton_clicked();

    void on_deleteButton_clicked();

    void on_clearLeftButton_clicked();

    void on_clearRightButton_clicked();

    void on_clearAllButton_clicked();

    void on_sortLeftButton_clicked();

    void on_sortRightButton_clicked();

    void on_sortAllButton_clicked();

    void on_MultiSelectionButton_stateChanged(int arg1);

    void on_viewModeAllButton_stateChanged(int arg1);

private:
    Ui::MainWindow *ui;
    QListWidget *leftList, *rightList;
};
#endif // MAINWINDOW_H
