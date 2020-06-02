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
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QGroupBox *groupBox;
    QPushButton *rotateButton;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLineEdit *rot_xEdit;
    QLineEdit *rot_yEdit;
    QLineEdit *rot_zEdit;
    QGroupBox *groupBox_2;
    QPushButton *scaleButton;
    QLabel *label_2;
    QLineEdit *zoom_kEdit;
    QGroupBox *groupBox_3;
    QPushButton *transferButton;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLineEdit *dzEdit;
    QLineEdit *dyEdit;
    QLineEdit *dxEdit;
    QPushButton *loadButton;
    QGraphicsView *graphicsView;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QString::fromUtf8("MainWindow"));
        MainWindow->resize(660, 462);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        groupBox = new QGroupBox(centralWidget);
        groupBox->setObjectName(QString::fromUtf8("groupBox"));
        groupBox->setGeometry(QRect(470, 100, 181, 131));
        rotateButton = new QPushButton(groupBox);
        rotateButton->setObjectName(QString::fromUtf8("rotateButton"));
        rotateButton->setGeometry(QRect(50, 100, 89, 25));
        label_3 = new QLabel(groupBox);
        label_3->setObjectName(QString::fromUtf8("label_3"));
        label_3->setGeometry(QRect(10, 30, 16, 21));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName(QString::fromUtf8("label_4"));
        label_4->setGeometry(QRect(10, 50, 16, 21));
        label_5 = new QLabel(groupBox);
        label_5->setObjectName(QString::fromUtf8("label_5"));
        label_5->setGeometry(QRect(10, 70, 16, 21));
        rot_xEdit = new QLineEdit(groupBox);
        rot_xEdit->setObjectName(QString::fromUtf8("rot_xEdit"));
        rot_xEdit->setGeometry(QRect(40, 30, 121, 21));
        rot_yEdit = new QLineEdit(groupBox);
        rot_yEdit->setObjectName(QString::fromUtf8("rot_yEdit"));
        rot_yEdit->setGeometry(QRect(40, 50, 121, 21));
        rot_zEdit = new QLineEdit(groupBox);
        rot_zEdit->setObjectName(QString::fromUtf8("rot_zEdit"));
        rot_zEdit->setGeometry(QRect(40, 70, 121, 21));
        groupBox_2 = new QGroupBox(centralWidget);
        groupBox_2->setObjectName(QString::fromUtf8("groupBox_2"));
        groupBox_2->setGeometry(QRect(470, 0, 181, 101));
        scaleButton = new QPushButton(groupBox_2);
        scaleButton->setObjectName(QString::fromUtf8("scaleButton"));
        scaleButton->setGeometry(QRect(30, 70, 141, 25));
        label_2 = new QLabel(groupBox_2);
        label_2->setObjectName(QString::fromUtf8("label_2"));
        label_2->setGeometry(QRect(10, 30, 16, 21));
        zoom_kEdit = new QLineEdit(groupBox_2);
        zoom_kEdit->setObjectName(QString::fromUtf8("zoom_kEdit"));
        zoom_kEdit->setGeometry(QRect(40, 30, 121, 21));
        groupBox_3 = new QGroupBox(centralWidget);
        groupBox_3->setObjectName(QString::fromUtf8("groupBox_3"));
        groupBox_3->setGeometry(QRect(470, 230, 181, 131));
        transferButton = new QPushButton(groupBox_3);
        transferButton->setObjectName(QString::fromUtf8("transferButton"));
        transferButton->setGeometry(QRect(50, 100, 89, 25));
        label_6 = new QLabel(groupBox_3);
        label_6->setObjectName(QString::fromUtf8("label_6"));
        label_6->setGeometry(QRect(10, 30, 21, 21));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QString::fromUtf8("label_7"));
        label_7->setGeometry(QRect(10, 50, 21, 21));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QString::fromUtf8("label_8"));
        label_8->setGeometry(QRect(10, 70, 21, 21));
        dzEdit = new QLineEdit(groupBox_3);
        dzEdit->setObjectName(QString::fromUtf8("dzEdit"));
        dzEdit->setGeometry(QRect(40, 70, 121, 21));
        dyEdit = new QLineEdit(groupBox_3);
        dyEdit->setObjectName(QString::fromUtf8("dyEdit"));
        dyEdit->setGeometry(QRect(40, 50, 121, 21));
        dxEdit = new QLineEdit(groupBox_3);
        dxEdit->setObjectName(QString::fromUtf8("dxEdit"));
        dxEdit->setGeometry(QRect(40, 30, 121, 21));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QString::fromUtf8("loadButton"));
        loadButton->setGeometry(QRect(470, 370, 181, 25));
        graphicsView = new QGraphicsView(centralWidget);
        graphicsView->setObjectName(QString::fromUtf8("graphicsView"));
        graphicsView->setGeometry(QRect(0, 0, 461, 401));
        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 660, 22));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QString::fromUtf8("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        MainWindow->setStatusBar(statusBar);
        QWidget::setTabOrder(zoom_kEdit, scaleButton);
        QWidget::setTabOrder(scaleButton, rot_xEdit);
        QWidget::setTabOrder(rot_xEdit, rot_yEdit);
        QWidget::setTabOrder(rot_yEdit, rot_zEdit);
        QWidget::setTabOrder(rot_zEdit, rotateButton);
        QWidget::setTabOrder(rotateButton, dxEdit);
        QWidget::setTabOrder(dxEdit, dyEdit);
        QWidget::setTabOrder(dyEdit, dzEdit);
        QWidget::setTabOrder(dzEdit, transferButton);
        QWidget::setTabOrder(transferButton, loadButton);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\276\321\200\320\276\321\202", nullptr));
        rotateButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\276\320\262\320\265\321\200\320\275\321\203\321\202\321\214", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "x: ", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "y: ", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "z: ", nullptr));
        groupBox_2->setTitle(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\320\275\320\270\320\265", nullptr));
        scaleButton->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\321\201\321\210\321\202\320\260\320\261\320\270\321\200\320\276\320\262\320\260\321\202\321\214", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "k: ", nullptr));
        groupBox_3->setTitle(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\276\321\201", nullptr));
        transferButton->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\275\320\265\321\201\321\202\320\270", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "dx: ", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "dy: ", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "dz: ", nullptr));
        loadButton->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\274\320\276\320\264\320\265\320\273\321\214", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
