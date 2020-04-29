#include <QtWidgets/QFileDialog>
#include <QtWidgets/QErrorMessage>
#include <QtGui/QIntValidator>

#include "controller/MainController.h"
#include "mainwindow.h"
#include "ui_mainwindow.h"

static void showError(QString errMsg) {
    QErrorMessage errorMessage;
    errorMessage.showMessage(errMsg);
    errorMessage.exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setWindowTitle("Лабораторная работа 1");

    this->setSizePolicy(QSizePolicy::Expanding, QSizePolicy::Expanding);    // Растягиваем содержимое по виджету

    par = parent;
    ui->setupUi(this);
    validator = new QRegExpValidator(QRegExp("^[+-]?[0-9]{0,5}(\\.|,|$)[0-9]{0,4}$"));
    ui->zoom_kEdit->setValidator(validator);
    ui->rot_xEdit->setValidator(validator);
    ui->rot_yEdit->setValidator(validator);
    ui->rot_zEdit->setValidator(validator);

    ui->dxEdit->setValidator(validator);
    ui->dyEdit->setValidator(validator);
    ui->dzEdit->setValidator(validator);

    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);
    int width = ui->graphicsView->width();
    int height = ui->graphicsView->height();

    scene->setSceneRect(0, 0, width, height);
}
MainWindow::~MainWindow() {
    argument arg;
    arg.none = nullptr;
    process(DESTROY, arg);

    delete validator;
    delete scene;
    delete ui;
}

void MainWindow::on_scaleButton_clicked() {
    double k = ui->zoom_kEdit->text().toDouble();
    if (k == 0) {
        showError("Incorrect input");
    }

    argument arg;
    arg.scale_act.k = k;

    err_t rc = process(SCALE, arg);
    QString msg = "";
    if(rc == ERROR_MODEL_EMPTY) {
        msg = "First load model!";
    } else if (rc != ERROR_OK) {
        msg = "Internal error. ";
    }

    if (msg != "") {
        showError(msg);
    } else {
        draw();
    }
}

void MainWindow::on_rotateButton_clicked() {
    double x = ui->rot_xEdit->text().toDouble();
    double y = ui->rot_yEdit->text().toDouble();
    double z = ui->rot_zEdit->text().toDouble();

    argument arg;
    arg.rotate_act.x = x;
    arg.rotate_act.y = y;
    arg.rotate_act.z = z;

    err_t rc = process(ROTATE, arg);
    QString msg = "";
    if(rc == ERROR_MODEL_EMPTY) {
        msg = "First load model!";
    } else if (rc != ERROR_OK) {
        msg = "Internal error. ";
    }

    if (msg != "") {
        showError(msg);
    } else {
        draw();
    }
}

void MainWindow::on_transferButton_clicked() {
    double dx = ui->dxEdit->text().toDouble();
    double dy = ui->dyEdit->text().toDouble();
    double dz = ui->dzEdit->text().toDouble();

    argument arg;
    arg.transfer_act.dx = dx;
    arg.transfer_act.dy = dy;
    arg.transfer_act.dz = dz;

    err_t rc = process(TRANSFER, arg);
    QString msg = "";
    if(rc == ERROR_MODEL_EMPTY) {
        msg = "First load model!";
    } else if (rc != ERROR_OK) {
        msg = "Internal error.";
    }

    if (msg != "") {
        showError(msg);
    } else {
        draw();
    }
}

void MainWindow::on_loadButton_clicked() {
    // /*
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if (str == "")
        return;
    // */

    argument arg;
    arg.load_act = str.toLatin1().data();
    err_t rc = process(LOAD, arg);

    QString msg = "";
    if(rc == ERROR_FOPEN) {
        msg = "Cannot open file";
    } else if(rc == ERROR_INPUT) {
        msg = "Input error";
    } else if (rc != ERROR_OK) {
        msg = "Internal error.";
    }

    if (msg != "") {
        showError(msg);

        return;
    } else {
        draw();
    }
}

void MainWindow::draw() {
    argument arg;
    arg.draw_act = this->scene;
    err_t rc = process(DRAW, arg);
    QString msg = "";
    if (rc != ERROR_OK) {
        msg = "Internal error.";
    }

    if (msg != "") {
        showError(msg);

        return;
    }
}

