/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.14.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLCDNumber>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QLCDNumber *lcd;
    QGroupBox *groupBox;
    QPushButton *floor_1;
    QPushButton *floor_2;
    QPushButton *floor_3;
    QPushButton *floor_4;
    QPushButton *floor_5;
    QGroupBox *groupBox_2;
    QPushButton *b_5;
    QPushButton *b_4;
    QPushButton *b_1;
    QPushButton *b_3;
    QPushButton *b_2;
    QTextEdit *log;
    QLabel *label;
    QLabel *label_2;
    QLabel *lift_state;
    QLabel *door_state;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(901, 368);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        lcd = new QLCDNumber(centralWidget);
        lcd->setObjectName(QString::fromUtf8("lcd"));
        lcd->setGeometry(QRect(110, 210, 64, 23));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(10, 10, 131, 191));
        floor_1 = new QPushButton(groupBox);
        floor_1->setObjectName(QString::fromUtf8("floor_1"));
        floor_1->setGeometry(QRect(50, 30, 31, 25));
        floor_2 = new QPushButton(groupBox);
        floor_2->setObjectName(QString::fromUtf8("floor_2"));
        floor_2->setGeometry(QRect(50, 60, 31, 25));
        floor_3 = new QPushButton(groupBox);
        floor_3->setObjectName(QString::fromUtf8("floor_3"));
        floor_3->setGeometry(QRect(50, 90, 31, 25));
        floor_4 = new QPushButton(groupBox);
        floor_4->setObjectName(QString::fromUtf8("floor_4"));
        floor_4->setGeometry(QRect(50, 120, 31, 25));
        floor_5 = new QPushButton(groupBox);
        floor_5->setObjectName(QString::fromUtf8("floor_5"));
        floor_5->setGeometry(QRect(50, 150, 31, 25));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(160, 10, 131, 191));
        b_5 = new QPushButton(groupBox_2);
        b_5->setObjectName(QString::fromUtf8("b_5"));
        b_5->setGeometry(QRect(50, 150, 31, 25));
        b_4 = new QPushButton(groupBox_2);
        b_4->setObjectName(QString::fromUtf8("b_4"));
        b_4->setGeometry(QRect(50, 120, 31, 25));
        b_1 = new QPushButton(groupBox_2);
        b_1->setObjectName(QString::fromUtf8("b_1"));
        b_1->setGeometry(QRect(50, 30, 31, 25));
        b_3 = new QPushButton(groupBox_2);
        b_3->setObjectName(QString::fromUtf8("b_3"));
        b_3->setGeometry(QRect(50, 90, 31, 25));
        b_2 = new QPushButton(groupBox_2);
        b_2->setObjectName(QString::fromUtf8("b_2"));
        b_2->setGeometry(QRect(50, 60, 31, 25));
        log = new QTextEdit(centralWidget);
        log->setObjectName(QString::fromUtf8("log"));
        log->setGeometry(QRect(380, 10, 501, 291));
        label = new QLabel(centralWidget);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(20, 240, 61, 17));
        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(20, 270, 61, 17));
        lift_state = new QLabel(centralWidget);
        lift_state->setObjectName(QString::fromUtf8("lift_state"));
        lift_state->setGeometry(QRect(80, 240, 141, 17));
        door_state = new QLabel(centralWidget);
        door_state->setObjectName(QString::fromUtf8("door_state"));
        door_state->setGeometry(QRect(80, 270, 141, 17));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 901, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\270 \320\275\320\260 \321\215\321\202\320\260\320\266\320\260\321\205", nullptr));
        floor_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        floor_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        floor_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        floor_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        floor_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\232\320\275\320\276\320\277\320\272\320\270 \320\262 \320\273\320\270\321\204\321\202\320\265", nullptr));
        b_5->setText(QCoreApplication::translate("MainWindow", "5", nullptr));
        b_4->setText(QCoreApplication::translate("MainWindow", "4", nullptr));
        b_1->setText(QCoreApplication::translate("MainWindow", "1", nullptr));
        b_3->setText(QCoreApplication::translate("MainWindow", "3", nullptr));
        b_2->setText(QCoreApplication::translate("MainWindow", "2", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "\320\233\320\270\321\204\321\202:", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "\320\224\320\262\320\265\321\200\320\270:", nullptr));
        lift_state->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
        door_state->setText(QCoreApplication::translate("MainWindow", "None", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
