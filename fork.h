#ifndef FORK_H
#define FORK_H
#include <QMutex>

class Fork
{
public:
    int Number;
    QMutex Fork_Mutex;
};

#endif // FORK_H
