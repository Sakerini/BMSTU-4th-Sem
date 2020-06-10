#ifndef DOORS_H
#define DOORS_H

#include <QObject>
#include <QLabel>
#include <QTimer>

//class Lift;

class Doors : public QObject
{
    Q_OBJECT

    enum State
    {
        OPENED,
        CLOSED,
        OPENING,
        CLOSING
    };

public:
    explicit Doors(QLabel *_doors_label);
    ~Doors();

    void setLabel(QLabel *l);

private:
    State state { CLOSED };
    QLabel *doorsLabel { nullptr };

    void setState(State state);

    QTimer *openingTimer { nullptr };
    QTimer *closingTimer { nullptr };
    QTimer *waitingTimer { nullptr };

public slots:
    void startOpen();
    void startClose();
    void open();
    void close();

signals:
    void onClosing();
    void onOpened();
    void onClosed();
};

#endif
