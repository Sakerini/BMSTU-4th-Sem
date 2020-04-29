#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QRegExpValidator>
#include <QGraphicsScene>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_transferButton_clicked();

    void on_loadButton_clicked();

private:
    void draw();

    Ui::MainWindow *ui;

    QWidget *par;
    QRegExpValidator *validator;
    QGraphicsScene * scene;
};

#endif // MAINWINDOW_H
