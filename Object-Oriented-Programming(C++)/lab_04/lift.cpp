#include "lift.h"
#include "error.h"

#define INDEX(i) (i - minFloor)

// Lift::Lift(QObject *parent, QTextEdit *_log, QLabel *doors, QLabel *lift, QLCDNumber *_screen) : QObject(parent),
Lift::Lift(QTextEdit *_log, QLabel *doors, QLabel *lift, QLCDNumber *_screen) : QObject(),
log(_log),
doorsLabel(doors),
liftLabel(lift),
screen(_screen)
{
    goUpTimer = new QTimer;
    goDownTimer = new QTimer;

    goUpTimer->setSingleShot(true);
    goDownTimer->setSingleShot(true);

    this->minFloor = 1;
    this->maxFloor = 5;
    setCurrentFloor(minFloor);
    this->doors = new Doors { doorsLabel };
    this->state = WAITING;
    this->direction = IDLE;
    this->pushedFloors = new bool[this->maxFloor - this->minFloor + 1];
    for (int i = 0; i <= INDEX(maxFloor); i++)
        this->pushedFloors[i] = false;

    connect(goUpTimer, SIGNAL(timeout()), this, SIGNAL(onGoUp()));
    connect(goDownTimer, SIGNAL(timeout()), this, SIGNAL(onGoDown()));

    connect(this, SIGNAL(onRide()), this, SLOT(findNextFloor()));
    connect(this, SIGNAL(onWait()), this, SLOT(wait()));

    connect(this, SIGNAL(onGoDown()), this, SLOT(goDown()));
    connect(this, SIGNAL(onGoUp()), this, SLOT(goUp()));

    connect(this, SIGNAL(onOpening()), this, SLOT(open()));
    connect(this, SIGNAL(onOpening()), this->doors, SLOT(startOpen()));

    connect(this->doors, SIGNAL(onClosed()), this, SIGNAL(onRide()));
}

Lift::~Lift()
{
    delete goUpTimer;
    delete goDownTimer;

    delete[] pushedFloors;
    delete doors;
}

void Lift::set_log(QTextEdit *log)
{
    this->log = log;
}

void Lift::set_labels(QLabel *doors, QLabel *lift, QLCDNumber *screen)
{
    this->doors->setLabel(doors);
    this->doorsLabel = doors;
    this->liftLabel = lift;
    this->screen = screen;
}


void Lift::setCurrentFloor(int floor)
{
    if (floor < minFloor || floor > maxFloor)
    {
        throw OutOfBoundsException(__FILE__, __LINE__, __FUNCTION__);
    }
    else
    {
        currFloor = floor;
        this->screen->display(currFloor);
    }
}

bool Lift::getNextFloor(int &next, Direction direction)
{
    if (direction == IDLE ) {
        bool tmp = getNextFloor(next, UP);
        if (tmp)
            return tmp;
        else
            return getNextFloor(next, DOWN);
    }

    if (direction == UP) {
        for (int i = currFloor + 1; i <= maxFloor; i++) {
            if (pushedFloors[INDEX(i)]) {
                next = i;
                return true;
            }
        }

        for (int i = currFloor - 1; i >= minFloor; i--) {
            if (pushedFloors[INDEX(i)]) {
                next = i;
                return true;
            }
        }
    }

    if (direction == DOWN) {
        for (int i = currFloor - 1; i >= minFloor; i--) {
            if (pushedFloors[INDEX(i)]) {
                next = i;
                return true;
            }
        }

        for (int i = currFloor + 1; i <= maxFloor; i++) {
            if (pushedFloors[INDEX(i)]) {
                next = i;
                return true;
            }
        }
    }

    return false;
}


void Lift::get_order(int order) {

    if (order < minFloor || order > maxFloor) {
        throw OutOfBoundsException(__FILE__, __LINE__, __FUNCTION__);
    } else {
        pushedFloors[INDEX(order)] = true;
        if (state == WAITING)
            emit onRide();
    }
}

void Lift::findNextFloor() {
    int next;

    if (getNextFloor(next, direction)) {
        if (next == currFloor)
                emit onOpening();
        else if (next < currFloor) {
            direction = DOWN;
            //emit onGoDown();
            setState(GOING_DOWN);
            goDownTimer->start(1500);
        } else {
            direction = UP;
            //emit onGoUp();
            setState(GOING_UP);
            goUpTimer->start(1500);
        }
    } else {
        setState(WAITING);
        direction = IDLE;
    }
}

void Lift::setState(State state) {
    this->log->append("Лифт ");
    this->state = state;

    QString msg;

    switch (state) {
    case GOING_UP:
        msg = "поднимается вверх...";
        this->liftLabel->setText("Поднимается наверх");
        break;
    case GOING_DOWN:
        msg = "опускается вниз...";
        this->liftLabel->setText("Опускается вниз");
        break;
    case OPENED:
        msg = "Лифт отркывает двери и ждеть их закритие...";
        this->liftLabel->setText("Открывает двери");
        break;
    case WAITING:
        msg = "ждет...";
        this->liftLabel->setText("Ждущий режим");
        break;
    default:
        msg = "изменил свое состояние на неизвестное!..";
        this->liftLabel->setText("Неизвестное");
        break;
    }

    this->log->insertPlainText(msg);
}

void Lift::goUp()
{
    //setState(GOING_UP);
    //delay(1500);
    setCurrentFloor(currFloor + 1);

    if (pushedFloors[INDEX(currFloor)])
    {
        pushedFloors[INDEX(currFloor)] = false;
        emit onOpening();
    }
    else
    {
        //emit onGoUp();
        setState(GOING_UP);
        goUpTimer->start(1500);
    }
}

void Lift::goDown()
{
    //this->setState(GOING_DOWN);
    //delay(1500);
    setCurrentFloor(currFloor - 1);

    if (pushedFloors[INDEX(currFloor)] == true)
    {
        pushedFloors[INDEX(currFloor)] = false;
        emit onOpening();
    }
    else
    {
        //emit onGoDown();
        setState(GOING_DOWN);
        goDownTimer->start(1500);
    }
}

void Lift::open()
{
    setState(OPENED);
}

void Lift::wait()
{
    setState(WAITING);
}

Lift::State Lift::getState() const {
    return state;
}
