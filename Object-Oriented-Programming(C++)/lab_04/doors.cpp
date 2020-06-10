#include "doors.h"
#include "delay.h"
#include "error.h"

/*
Doors::Doors(Lift *lift) : QObject ()
{
    this->state = CLOSED;
    this->lift = lift;
    connect(this, SIGNAL(open()), this, SLOT(open_doors()));
    connect(this, SIGNAL(close()), this, SLOT(close_doors()));

    connect(this, SIGNAL(opened()), this->lift, SLOT(close_doors()));
    connect(this, SIGNAL(opened()), this->lift, SLOT(open_doors()));
    connect(this, SIGNAL(closed()), this->lift, SLOT(close_doors()));
}
*/

Doors::Doors(QLabel *_doorsLabel) : QObject (),
doorsLabel(_doorsLabel),
state(CLOSED)
{
    openingTimer = new QTimer;
    closingTimer = new QTimer;
    waitingTimer = new QTimer;

    openingTimer->setSingleShot(true);
    closingTimer->setSingleShot(true);
    waitingTimer->setSingleShot(true);

    connect(this->openingTimer, SIGNAL(timeout()), this, SIGNAL(onOpened()));
    connect(this->closingTimer, SIGNAL(timeout()), this, SIGNAL(onClosed()));
    connect(this->waitingTimer, SIGNAL(timeout()), this, SIGNAL(onClosing()));
    connect(this, SIGNAL(onClosing()), this, SLOT(startClose()));
    connect(this, SIGNAL(onOpened()), this, SLOT(open()));
    connect(this, SIGNAL(onClosed()), this, SLOT(close()));
}

Doors::~Doors() {
    delete openingTimer;
    delete closingTimer;
    delete waitingTimer;
};

void Doors::setLabel(QLabel *l)
{
    this->doorsLabel = l;
}

void Doors::setState(State state)
{
    this->state = state;

    switch (state)
    {
    case OPENED:
        this->doorsLabel->setText("Открыты");
        break;
    case CLOSED:
        this->doorsLabel->setText("Закрыты");
        break;
    case OPENING:
        this->doorsLabel->setText("Открываются");
        break;
    case CLOSING:
        this->doorsLabel->setText("Закрываются");
        break;
    default:
        this->doorsLabel->setText("UNKNOWN");
        throw UnknownStateException(__FILE__, __LINE__, __FUNCTION__);
    }
}

void Doors::startOpen()
{
    if (this->state == OPENING || OPENED)
        return;

    int interval = 1000;
    if (this->state == CLOSING) {
        interval = closingTimer->interval();
        closingTimer->stop();
    }

    this->setState(OPENING);
    //delay(1000);
    //emit onOpened();
    openingTimer->start(interval);
}

void Doors::startClose()
{
    if (this->state == CLOSING || this->state == CLOSED)
        return;

    int interval = 1000;
    if (this->state == OPENING) {
        interval = openingTimer->interval();
        openingTimer->stop();
    }
    else if (this->state == OPENED) {
        waitingTimer->stop();
    }

    this->setState(CLOSING);
    //delay(1000);
    //emit onClosed();
    closingTimer->start(interval);
}

void Doors::open() {
    setState(OPENED);
    //delay(2000);
    //emit onClosing();
    waitingTimer->start(1000);
}

void Doors::close() {
    setState(CLOSED);
}

