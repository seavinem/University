#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QMessageBox>
#include <QInputDialog>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    leftList = ui->leftListWidget;
    rightList = ui->rightListWidget;
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_leftToRightButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = leftList->selectedItems();
    for (QListWidgetItem* item : selectedItems) {
        QListWidgetItem* newItem = new QListWidgetItem(*item);
        leftList->removeItemWidget(item);
        rightList->addItem(newItem);
    }
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        QListWidgetItem* item = leftList->takeItem(leftList->row(selectedItems[i]));
        delete item;
    }
}


void MainWindow::on_rightToLeftButton_clicked()
{
    QList<QListWidgetItem*> selectedItems = rightList->selectedItems();
    for (QListWidgetItem* item : selectedItems) {
        QListWidgetItem* newItem = new QListWidgetItem(*item);
        rightList->removeItemWidget(item);
        leftList->addItem(newItem);
    }
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        QListWidgetItem* item = rightList->takeItem(rightList->row(selectedItems[i]));
        delete item;
    }
}


void MainWindow::on_editButton_clicked()
{
    QListWidgetItem *item = leftList->currentItem();
    if (!item) {
        item = rightList->currentItem();
    }

    if (item) {
        bool ok;
        QString text = QInputDialog::getText(this, "Изменить элемент", "Введите новое значение:", QLineEdit::Normal, item->text(), &ok);
        if (ok && !text.isEmpty()) {
            item->setText(text);
        }
    }
}


void MainWindow::on_addLeftButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Добавить элемент", "Введите значение:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        leftList->addItem(text);
    }
}


void MainWindow::on_addRightButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Добавить элемент", "Введите значение:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        rightList->addItem(text);
    }
}


void MainWindow::on_addAllButton_clicked()
{
    bool ok;
    QString text = QInputDialog::getText(this, "Добавить элемент", "Введите значение:", QLineEdit::Normal, "", &ok);
    if (ok && !text.isEmpty()) {
        leftList->addItem(text);
        rightList->addItem(text);
    }
}


void MainWindow::on_deleteButton_clicked()
{

    QList<QListWidgetItem*> selectedItems = leftList->selectedItems();
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        QListWidgetItem* item = leftList->takeItem(leftList->row(selectedItems[i]));
        delete item;
    }

    selectedItems = rightList->selectedItems();
    for (int i = selectedItems.size() - 1; i >= 0; --i) {
        QListWidgetItem* item = rightList->takeItem(rightList->row(selectedItems[i]));
        delete item;
    }

}


void MainWindow::on_clearLeftButton_clicked()
{
    leftList->clear();
}


void MainWindow::on_clearRightButton_clicked()
{
    rightList->clear();
}


void MainWindow::on_clearAllButton_clicked()
{
    leftList->clear();
    rightList->clear();
}


void MainWindow::on_sortLeftButton_clicked()
{
    leftList->sortItems(Qt::AscendingOrder);
}


void MainWindow::on_sortRightButton_clicked()
{
    rightList->sortItems(Qt::DescendingOrder);
}


void MainWindow::on_sortAllButton_clicked()
{
    leftList->sortItems(Qt::AscendingOrder);
    rightList->sortItems(Qt::DescendingOrder);
}

void MainWindow::on_MultiSelectionButton_stateChanged(int arg1)
{
    bool isMultiSelectionMode = ui->MultiSelectionButton->isChecked();
    leftList->setSelectionMode(isMultiSelectionMode ? QAbstractItemView::MultiSelection : QAbstractItemView::SingleSelection);
    rightList->setSelectionMode(isMultiSelectionMode ? QAbstractItemView::MultiSelection : QAbstractItemView::SingleSelection);
}


void MainWindow::on_viewModeAllButton_stateChanged(int arg1)
{
    bool isIconMode = ui->viewModeAllButton->isChecked();
    leftList->setViewMode(isIconMode ? QListWidget::IconMode : QListWidget::ListMode);
    rightList->setViewMode(isIconMode ? QListWidget::IconMode : QListWidget::ListMode);
}

