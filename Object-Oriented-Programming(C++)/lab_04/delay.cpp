#include "delay.h"

void delay(int m_sec)
{
    QTime dieTime= QTime::currentTime().addMSecs(m_sec);
    while (QTime::currentTime() < dieTime)
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}
