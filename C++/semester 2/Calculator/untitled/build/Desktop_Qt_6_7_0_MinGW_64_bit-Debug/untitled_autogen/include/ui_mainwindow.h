/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QLabel *result_show;
    QPushButton *pushButton;
    QPushButton *pushButton_prosen;
    QPushButton *pushButton_znak;
    QPushButton *pushButton_del;
    QPushButton *pushButton_9;
    QPushButton *pushButton_7;
    QPushButton *pushButton_8;
    QPushButton *pushButton_add;
    QPushButton *pushButton_6;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QPushButton *pushButton_min;
    QPushButton *pushButton_3;
    QPushButton *pushButton_1;
    QPushButton *pushButton_2;
    QPushButton *pushButton_sum;
    QPushButton *pushButton_dot;
    QPushButton *pushButton_0;
    QPushButton *pushButton_ravno;
    QPushButton *pushButton_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(243, 372);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        result_show = new QLabel(centralwidget);
        result_show->setObjectName("result_show");
        result_show->setGeometry(QRect(3, 6, 240, 61));
        QFont font;
        font.setPointSize(20);
        font.setBold(false);
        font.setItalic(false);
        font.setUnderline(false);
        result_show->setFont(font);
        result_show->setStyleSheet(QString::fromUtf8("QLabel {\n"
" qproperty-alignment: 'AlignVCenter | AlignRight';\n"
" border-bottom: 1px solid gray;\n"
"}\n"
"\n"
"background-color : white;"));
        pushButton = new QPushButton(centralwidget);
        pushButton->setObjectName("pushButton");
        pushButton->setGeometry(QRect(0, 70, 62, 62));
        pushButton->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(215, 215, 215);\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7\342\202\2757);\n"
"}"));
        pushButton_prosen = new QPushButton(centralwidget);
        pushButton_prosen->setObjectName("pushButton_prosen");
        pushButton_prosen->setGeometry(QRect(121, 70, 62, 62));
        pushButton_prosen->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(215, 215, 215);\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7\342\202\2757);\n"
"}"));
        pushButton_znak = new QPushButton(centralwidget);
        pushButton_znak->setObjectName("pushButton_znak");
        pushButton_znak->setGeometry(QRect(61, 70, 62, 62));
        pushButton_znak->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(215, 215, 215);\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7\342\202\2757);\n"
"}"));
        pushButton_del = new QPushButton(centralwidget);
        pushButton_del->setObjectName("pushButton_del");
        pushButton_del->setGeometry(QRect(181, 70, 62, 62));
        pushButton_del->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 151, 57);\n"
"color white;\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_9 = new QPushButton(centralwidget);
        pushButton_9->setObjectName("pushButton_9");
        pushButton_9->setGeometry(QRect(121, 130, 61, 61));
        pushButton_9->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_7 = new QPushButton(centralwidget);
        pushButton_7->setObjectName("pushButton_7");
        pushButton_7->setGeometry(QRect(0, 130, 61, 61));
        pushButton_7->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_8 = new QPushButton(centralwidget);
        pushButton_8->setObjectName("pushButton_8");
        pushButton_8->setGeometry(QRect(61, 130, 61, 61));
        pushButton_8->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_add = new QPushButton(centralwidget);
        pushButton_add->setObjectName("pushButton_add");
        pushButton_add->setGeometry(QRect(181, 130, 62, 62));
        pushButton_add->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 151, 57);\n"
"color white;\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_6 = new QPushButton(centralwidget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setGeometry(QRect(121, 190, 61, 61));
        pushButton_6->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_4 = new QPushButton(centralwidget);
        pushButton_4->setObjectName("pushButton_4");
        pushButton_4->setGeometry(QRect(0, 190, 61, 61));
        pushButton_4->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_5 = new QPushButton(centralwidget);
        pushButton_5->setObjectName("pushButton_5");
        pushButton_5->setGeometry(QRect(61, 190, 61, 61));
        pushButton_5->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_min = new QPushButton(centralwidget);
        pushButton_min->setObjectName("pushButton_min");
        pushButton_min->setGeometry(QRect(181, 190, 62, 62));
        pushButton_min->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 151, 57);\n"
"color white;\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_3 = new QPushButton(centralwidget);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(121, 250, 61, 61));
        pushButton_3->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_1 = new QPushButton(centralwidget);
        pushButton_1->setObjectName("pushButton_1");
        pushButton_1->setGeometry(QRect(0, 250, 61, 61));
        pushButton_1->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_2 = new QPushButton(centralwidget);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(61, 250, 61, 61));
        pushButton_2->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_sum = new QPushButton(centralwidget);
        pushButton_sum->setObjectName("pushButton_sum");
        pushButton_sum->setGeometry(QRect(181, 250, 62, 62));
        pushButton_sum->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 151, 57);\n"
"color white;\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_dot = new QPushButton(centralwidget);
        pushButton_dot->setObjectName("pushButton_dot");
        pushButton_dot->setGeometry(QRect(121, 310, 62, 62));
        pushButton_dot->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(215, 215, 215);\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #BEBEBE, stop: 1 #D7D7\342\202\2757);\n"
"}"));
        pushButton_0 = new QPushButton(centralwidget);
        pushButton_0->setObjectName("pushButton_0");
        pushButton_0->setGeometry(QRect(0, 310, 121, 62));
        pushButton_0->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"backpround-color: qlineargradient(x1: y1: 0,x2: 0, y2: 1,\n"
"                                    stop: 0 #dadbode,stop: 1 #f6f7fa);\n"
"}"));
        pushButton_ravno = new QPushButton(centralwidget);
        pushButton_ravno->setObjectName("pushButton_ravno");
        pushButton_ravno->setGeometry(QRect(181, 310, 62, 62));
        pushButton_ravno->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"background-color: rgb(255, 151, 57);\n"
"color white;\n"
" border: 1px solid gray;\n"
"}\n"
"QPushButton:pressed {\n"
"background-color: qlineargradient (x1: 0, y1: 0, x2: 0, y2: 1,\n"
"                                      stop: 0 #FF7832, stop: 1 #FF9739);\n"
"}"));
        pushButton_10 = new QPushButton(centralwidget);
        pushButton_10->setObjectName("pushButton_10");
        pushButton_10->setGeometry(QRect(310, 320, 63, 63));
        pushButton_10->setMinimumSize(QSize(0, 0));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Sitka Display")});
        font1.setBold(false);
        font1.setUnderline(false);
        pushButton_10->setFont(font1);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        result_show->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton->setText(QCoreApplication::translate("MainWindow", "AC", nullptr));
        pushButton_prosen->setText(QCoreApplication::translate("MainWindow", "%", nullptr));
        pushButton_znak->setText(QCoreApplication::translate("MainWindow", "+/-", nullptr));
        pushButton_del->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
        pushButton_9->setText(QCoreApplication::translate("MainWindow", "9", nullptr));
        pushButton_7->setText(QCoreApplication::translate("MainWindow", "7", nullptr));
        pushButton_8->setText(QCoreApplication::translate("MainWindow", "8", nullptr));
        pushButton_add->setText(QCoreApplication::translate("MainWindow", "x", nullptr));
        pushButton_6->setText(QCoreApplication::translate("MainWindow", "6", nullptr));
        pushButton_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        pushButton_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        pushButton_min->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        pushButton_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        pushButton_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        pushButton_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        pushButton_sum->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        pushButton_dot->setText(QCoreApplication::translate("MainWindow", ".", nullptr));
        pushButton_0->setText(QCoreApplication::translate("MainWindow", "0", nullptr));
        pushButton_ravno->setText(QCoreApplication::translate("MainWindow", "=", nullptr));
        pushButton_10->setText(QCoreApplication::translate("MainWindow", "/", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
