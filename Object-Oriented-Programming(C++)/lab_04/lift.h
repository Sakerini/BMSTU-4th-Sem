#ifndef LIFT_H
#define LIFT_H

#include <QObject>
#include <QTextEdit>
#include <QLCDNumber>
#include <QLabel>
#include <QSet>

#include "doors.h"
#include "delay.h"

class Lift : public QObject
{
    Q_OBJECT
    enum State
    {
        GOING_UP,
        GOING_DOWN,
        OPENED,
        WAITING
    };

    enum Direction
    {
        UP,
        DOWN,
        IDLE
    };

public:
    //Lift(QObject *parent, QTextEdit *_log, QLabel *doors, QLabel *lift, QLCDNumber *_screen);
    Lift(QTextEdit *_log, QLabel *doors, QLabel *lift, QLCDNumber *_screen);
    virtual ~Lift();

    // Methods
    void set_log(QTextEdit *log);
    void set_labels(QLabel *doors, QLabel *lift, QLCDNumber *screen);
    void get_order(int order);

    State getState() const;
    void setState(State);

private:
    QTextEdit *log;
    QLCDNumber *screen;
    QLabel *doorsLabel;
    QLabel *liftLabel;

    QTimer *goUpTimer { nullptr };
    QTimer *goDownTimer { nullptr };

    int minFloor;
    int maxFloor;
    int currFloor; // Current floor

    Doors *doors;
    State state;
    Direction direction;
    bool *pushedFloors;

    void setCurrentFloor(int floor);
    bool getNextFloor(int &next, Direction direction);

public slots:
    void wait();
    void goUp();
    void goDown();
    void open();
    void findNextFloor();

signals:
    void onOpening();
    void onGoUp();
    void onGoDown();
    void onWait();

    void onRide();
};

#endif
