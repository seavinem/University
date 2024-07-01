#include "mainwindow.h"
#include "chartwidget.h"
#include <QFileDialog>
#include <QMessageBox>
#include <QCloseEvent>
#include <QColorDialog>
#include <QInputDialog>
#include <QMenuBar>
#include <QMenu>
#include <QAction>
#include <QStatusBar>
#include <QTextStream>
#include <QActionGroup>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), chartWidget(new ChartWidget(this))
{
    setCentralWidget(chartWidget);\

    createActions();
    createMenus();
    createContextMenu();
    updateStatusBar();

    setWindowTitle("Козлов_8_4");
    resize(800, 600);
}

MainWindow::~MainWindow()
{
}

void MainWindow::createActions()
{
    actionOpen = new QAction("Open", this);
    actionOpen->setShortcut(QKeySequence::Open);
    actionOpen->setDisabled(true);
    connect(actionOpen, &QAction::triggered, this, &MainWindow::onActionOpenTriggered);

    actionSave = new QAction("Save", this);
    actionSave->setShortcut(QKeySequence::Save);
    connect(actionSave, &QAction::triggered, this, &MainWindow::onActionSaveTriggered);

    actionSaveAs = new QAction("Save As", this);
    connect(actionSaveAs, &QAction::triggered, this, &MainWindow::onActionSaveAsTriggered);

    actionClose = new QAction("Close", this);
    actionClose->setShortcut(QKeySequence::Close);
    actionClose->setDisabled(true);
    connect(actionClose, &QAction::triggered, this, &MainWindow::onActionCloseTriggered);

    actionExit = new QAction("Exit", this);
    actionExit->setShortcut(Qt::ALT + Qt::Key_X);
    connect(actionExit, &QAction::triggered, this, &MainWindow::onActionExitTriggered);


    actionPenColor = new QAction("Color", this);
    connect(actionPenColor, &QAction::triggered, this, &MainWindow::onActionPenColorTriggered);

    actionPenStyle = new QAction("Style", this);
    connect(actionPenStyle, &QAction::triggered, this, &MainWindow::onActionPenStyleTriggered);


    actionBrushColor = new QAction("Color", this);
    connect(actionBrushColor, &QAction::triggered, this, &MainWindow::onActionBrushColorTriggered);


    actionAbout = new QAction("About", this);
    connect(actionAbout, &QAction::triggered, this, &MainWindow::onActionAboutTriggered);
}

void MainWindow::createMenus()
{
    QMenu *fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(actionOpen);
    fileMenu->addAction(actionSave);
    fileMenu->addAction(actionSaveAs);
    fileMenu->addAction(actionClose);
    fileMenu->addSeparator();
    fileMenu->addAction(actionExit);


    QMenu *penMenu = menuBar()->addMenu("Pen");
    penMenu->addAction(actionPenColor);
    penMenu->addAction(actionPenStyle);


    QMenu *brushMenu = menuBar()->addMenu("Brush");
    brushMenu->addAction(actionBrushColor);


    QMenu *helpMenu = menuBar()->addMenu("Help");
    helpMenu->addAction(actionAbout);
}

void MainWindow::createContextMenu()
{
    chartWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

    QActionGroup *penWidthGroup = new QActionGroup(this);

    QAction *actionSetPenWidth1 = new QAction("1 px", this);
    actionSetPenWidth1->setCheckable(true);
    actionSetPenWidth1->setChecked(true);
    penWidthGroup->addAction(actionSetPenWidth1);

    QAction *actionSetPenWidth2 = new QAction("2 px", this);
    actionSetPenWidth2->setCheckable(true);
    penWidthGroup->addAction(actionSetPenWidth2);

    QAction *actionSetPenWidth3 = new QAction("3 px", this);
    actionSetPenWidth3->setCheckable(true);
    penWidthGroup->addAction(actionSetPenWidth3);

    connect(actionSetPenWidth1, &QAction::triggered, [this]() {
        chartWidget->setPenWidth(1);
        updateStatusBar();
    });
    connect(actionSetPenWidth2, &QAction::triggered, [this]() {
        chartWidget->setPenWidth(2);
        updateStatusBar();
    });
    connect(actionSetPenWidth3, &QAction::triggered, [this]() {
        chartWidget->setPenWidth(3);
        updateStatusBar();
    });

    chartWidget->addAction(actionSetPenWidth1);
    chartWidget->addAction(actionSetPenWidth2);
    chartWidget->addAction(actionSetPenWidth3);
}

void MainWindow::updateStatusBar()
{
    QString status = "File:" +  (currentFile.isEmpty() ? "Untitled" : currentFile) + " | Pen: " + QString::number(chartWidget->penWidth()) + " px, " + (chartWidget->penColor().name());
    statusBar()->showMessage(status);
}

void MainWindow::onActionOpenTriggered()
{
    if (maybeSave()) {
        QString fileName = QFileDialog::getOpenFileName(this, "Open File", QString(),
                                                        tr("Text Files (*.txt)"));
        if (!fileName.isEmpty()) {
            loadData(fileName);
        }
    }
}

void MainWindow::onActionSaveTriggered()
{
    if (currentFile.isEmpty()) {
        onActionSaveAsTriggered();
    } else {
        saveData(currentFile);
    }
}

void MainWindow::onActionSaveAsTriggered()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Save File", QString(),
                                                    tr("Text Files (*.txt)"));
    if (!fileName.isEmpty()) {
        saveData(fileName);
        actionOpen->setEnabled(true);
        actionClose->setEnabled(true);
    }
}

void MainWindow::onActionCloseTriggered()
{
    if (maybeSave()) {
        chartWidget->setData(QVector<int>());
        currentFile.clear();
        updateStatusBar();
    }
}

void MainWindow::onActionExitTriggered()
{
    close();
}

void MainWindow::onActionPenColorTriggered()
{
    QColor color = QColorDialog::getColor(chartWidget->penColor(), this, "Select Pen Color");
    if (color.isValid()) {
        chartWidget->setPenColor(color);
        updateStatusBar();
    }
}

void MainWindow::onActionPenStyleTriggered()
{
    bool ok;
    QStringList items = {"Solid", "Dash", "Dot"};
    QString item = QInputDialog::getItem(this, "Select Pen Style", "Style:", items, 0, false, &ok);
    if (ok && !item.isEmpty()) {
        Qt::PenStyle style;
        if (item == "Solid") {
            style = Qt::SolidLine;
        } else if (item == "Dash") {
            style = Qt::DashLine;
        } else if (item == "Dot") {
            style = Qt::DotLine;
        }
        chartWidget->setPenStyle(style);
        updateStatusBar();
    }
}

void MainWindow::onActionBrushColorTriggered()
{
    QColor color = QColorDialog::getColor(chartWidget->brushColor(), this, "Select Brush Color");
    if (color.isValid()) {
        chartWidget->setBrushColor(color);
        updateStatusBar();
    }
}

void MainWindow::onActionAboutTriggered()
{
    QMessageBox::about(this, "Info", "ФИО: Козлов Кирилл Сергеевич\nГруппа: 8\nНомер Варианта: 4");
}

void MainWindow::closeEvent(QCloseEvent *event)
{
    if (maybeSave()) {
        event->accept();
    } else {
        event->ignore();
    }
}

bool MainWindow::maybeSave()
{
    if (chartWidget->isModified()) {
        auto ret = QMessageBox::warning(this, "Warning", "Информация в приложении была изменена.\nХотите сохранить изменения?",
                                        QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);
        if (ret == QMessageBox::Save) {
            onActionSaveTriggered();
            return true;
        } else if (ret == QMessageBox::Cancel) {
            return false;
        }
    }
    return true;
}

void MainWindow::loadData(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly)) {
        QMessageBox::warning(this, "Error", "Ошибка чтения файла" + fileName + ": " + file.errorString());
        return;
    }

    QTextStream in(&file);
    QVector<int> data;
    while (!in.atEnd()) {
        int value;
        in >> value;
        if (value >= 0) {
            data.append(value);
        }
    }

    file.close();

    chartWidget->setData(data);
    currentFile = fileName;
    updateStatusBar();
}

void MainWindow::saveData(const QString &fileName)
{
    QFile file(fileName);
    if (!file.open(QIODevice::WriteOnly)) {
        QMessageBox::warning(this, "Error", "Ошибка чтения файла" + fileName + ": " + file.errorString());
        return;
    }

    QTextStream out(&file);
    const QVector<int> &data = chartWidget->data();
    for (int value : data) {
        out << value << "\n";
    }

    file.close();

    currentFile = fileName;
    statusBar()->showMessage("Файл сохранен", 2000);
}
