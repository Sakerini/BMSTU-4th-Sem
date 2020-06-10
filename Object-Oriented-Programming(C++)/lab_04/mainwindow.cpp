#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    lift = new Lift(ui->log, ui->door_state, ui->lift_state, ui->lcd);
    // lift.set_log(ui->log);
    // lift.set_labels(ui->door_state, ui->lift_state, ui->lcd);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete lift;
}

void MainWindow::on_floor_1_clicked()
{
    ui->log->append("Нажата кнопка вызова на первом этаже....");
    lift->get_order(1);
}

void MainWindow::on_floor_2_clicked()
{
    ui->log->append("Нажата кнопка вызова на втором этаже....");
    lift->get_order(2);
}

void MainWindow::on_floor_3_clicked()
{
    ui->log->append("Нажата кнопка вызова на третем этаже....");
    lift->get_order(3);
}

void MainWindow::on_floor_4_clicked()
{
    ui->log->append("Нажата кнопка вызова на четвертом этаже....");
    lift->get_order(4);
}

void MainWindow::on_floor_5_clicked()
{
    ui->log->append("Нажата кнопка вызова на пятом этаже....");
    lift->get_order(5);
}

void MainWindow::on_b_1_clicked()
{
    ui->log->append("Пассажир в лифте желает на первый этаж....");
    lift->get_order(1);
}

void MainWindow::on_b_2_clicked()
{
    ui->log->append("Пассажир в лифте желает на второй этаж....");
    lift->get_order(2);
}

void MainWindow::on_b_3_clicked()
{
    ui->log->append("Пассажир в лифте желает на третий этаж....");
    lift->get_order(3);
}

void MainWindow::on_b_4_clicked()
{
    ui->log->append("Пассажир в лифте желает на четвертый этаж....");
    lift->get_order(4);
}

void MainWindow::on_b_5_clicked()
{
    ui->log->append("Пассажир в лифте желает на пятый этаж....");
    lift->get_order(5);
}
