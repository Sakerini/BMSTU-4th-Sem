#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtGui/QRegExpValidator>
#include <QGraphicsScene>
#include <patterns/observer/subject.h>
#include "command/iappcommand.h"

namespace Ui {
class MainWindow;
}
class MainController;

class MainWindow : public QMainWindow, Subject
{
    Q_OBJECT
public:
    enum CMD {
        LOAD_MODEL,
        DRAW,
        GROUP,
        ROTATE,
        SCALE,
        TRANSFER,
        ADD_CAMERA,
        SET_ACTIVE_CAMERA

    };

    struct State {
        CMD cmd;
        IAppCommand::Argument arg;
    };

    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    State& getState();
    void setState(State &state);


private slots:
    void on_scaleButton_clicked();

    void on_rotateButton_clicked();

    void on_transferButton_clicked();

    void on_loadButton_clicked();

private:
    void draw();

    Ui::MainWindow *ui { nullptr };

    QWidget *par { nullptr };
    QRegExpValidator *validator { nullptr };
    QGraphicsScene *scene { nullptr };
    State _state;
    MainController *mainController { nullptr };
};

#endif // MAINWINDOW_H
