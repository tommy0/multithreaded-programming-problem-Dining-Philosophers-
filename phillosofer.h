#ifndef PHILLOSOFER_H
#define PHILLOSOFER_H
#include <fork.h>
#include <cheker.h>
#include <QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QTime>
#include <iostream>

class Phillosopher : public QThread
{
private:
    Fork Left;
    Fork Right;
    Cheker* Waiter;
public:
    Phillosopher();
    Phillosopher(int NameOfPhillosopher,int StateOfPhillosopher,int LeftFork,int RightFork, Cheker* MainMutex);
    int State;
    int NamePhil;
    void Think();
    void Eat();
    bool UpLeftFork();
    bool UpRightFork();
    void DownLeftFork();
    void DownRightFork();
    void run();
};
#endif // PHILLOSOFER_H
