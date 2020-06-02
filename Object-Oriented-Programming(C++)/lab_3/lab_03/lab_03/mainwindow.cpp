#include <QtWidgets/QFileDialog>
#include <QtWidgets/QErrorMessage>
#include <QtGui/QIntValidator>
#include <factory/iabstractfactory.h>
#include <factory/model3dfactory.h>
#include <controller/maincontroller.h>
#include <exception/error.h>
#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"

static void showError(QString errMsg) {
    QErrorMessage errorMessage;
    errorMessage.showMessage(errMsg);
    errorMessage.exec();
}

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    Subject()
{
    IAbstractFactory* factory = Model3dFactory::getInstance();
    mainController = factory->createMainController();
    this->attach(mainController);

    this->setWindowTitle("Лабораторная работа 3");

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
    delete mainController;

    delete validator;
    delete scene;
    delete ui;
}

void MainWindow::on_scaleButton_clicked() {
    double k = ui->zoom_kEdit->text().toDouble();
    if (k == 0) {
        showError("Incorrect input");
    }

    _state.cmd = SCALE;
    // TODO id
    _state.arg.motion.id = 0;
    _state.arg.motion.data.scale_act.k = k;

    bool exceptionHappaned = false;
    try {
        notify();
    } catch (std::exception& a) {
        std::cerr << a.what() << std::endl;
        showError("Model is not loaded");
        exceptionHappaned = true;
    }

    if (!exceptionHappaned)
        draw();
}

void MainWindow::on_rotateButton_clicked() {
    double alpha = ui->rot_xEdit->text().toDouble();
    double beta = ui->rot_yEdit->text().toDouble();
    double gamma = ui->rot_zEdit->text().toDouble();

    _state.cmd = ROTATE;
    // TODO id
    _state.arg.motion.id = 0;
    _state.arg.motion.data.rotate_act.alpha = alpha;
    _state.arg.motion.data.rotate_act.beta = beta;
    _state.arg.motion.data.rotate_act.alpha = gamma;

    bool exceptionHappaned = false;
    try {
        notify();
    } catch (std::exception& a) {
        std::cerr << a.what() << std::endl;
        showError("Error in execution of rotate");
        exceptionHappaned = true;
    }

    if (!exceptionHappaned)
        draw();
}

void MainWindow::on_transferButton_clicked() {
    double dx = ui->dxEdit->text().toDouble();
    double dy = ui->dyEdit->text().toDouble();
    double dz = ui->dzEdit->text().toDouble();

    _state.cmd = TRANSFER;
    // TODO id
    _state.arg.motion.id = 0;
    _state.arg.motion.data.transfer_act.dx = dx;
    _state.arg.motion.data.transfer_act.dy = dy;
    _state.arg.motion.data.transfer_act.dz = dz;

    bool exceptionHappaned = false;
    try {
        notify();
    } catch (std::exception& a) {
        std::cerr << a.what() << std::endl;
        showError("Error in execution of transfer");
        exceptionHappaned = true;
    }

    if (!exceptionHappaned)
        draw();
}

void MainWindow::on_loadButton_clicked() {
    // /*
    QString str = QFileDialog::getOpenFileName(0, "Open Dialog", "", "*.txt");
    if (str == "")
        return;
    // */

    _state.cmd = LOAD_MODEL;
    // TODO id
    _state.arg.load_act.id = 0;
    _state.arg.load_act.file = str.toLatin1().data();


    bool exceptionHappaned = false;
    try {
        notify();
    } catch (std::exception& a) {
        std::cerr << a.what() << std::endl;
        showError("Input error");
        exceptionHappaned = true;
    }

    if (!exceptionHappaned)
        draw();
}

void MainWindow::draw() {
    _state.cmd = DRAW;

    _state.arg.draw_act = this->scene;

    try {
        notify();
    } catch (std::exception& a) {
        std::cerr << a.what() << std::endl;
        showError("Can not draw");
    }
}

MainWindow::State& MainWindow::getState() {
    return this->_state;
}

void MainWindow::setState(State &state) {
    _state = state;
}
