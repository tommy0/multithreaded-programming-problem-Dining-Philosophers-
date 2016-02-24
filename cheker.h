#ifndef CHEKER_H
#define CHEKER_H
#include <setting.h>
#include <QMutex>
#define AMOUNT_PHILLOSOPHERS 5

class Cheker
{
public:
    Cheker();
    QMutex ChekerMutex;
    int StateFork[AMOUNT_PHILLOSOPHERS];
    int AmountFreeFork;
    bool Permission(int fork);
    void Returning();
};

#endif // CHEKER_H
