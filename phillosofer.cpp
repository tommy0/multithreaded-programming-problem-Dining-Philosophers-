#include <phillosofer.h>
#include <cheker.h>
#include <QCoreApplication>
#include <QThread>
#include <QMutex>
#include <QTime>
#include <QDebug>
#include <iostream>
#define THINKING 0
#define HUNGRY 1
#define EATING 2

using namespace std;

QMutex allow;

Phillosopher::Phillosopher(int NameOfPhillosopher,int StateOfPhillosopher,int LeftFork,int RightFork,Cheker* MyCheker)
{
    NamePhil=NameOfPhillosopher;
    State=StateOfPhillosopher;
    Left.Number=LeftFork;
    Right.Number=RightFork;
    Waiter=MyCheker;
}

void Phillosopher :: Think()
{
    allow.lock();
    cout<<"Phillosopher "<<NamePhil<<" thinking"<<endl;
    allow.unlock();
    sleep(1);
    State=HUNGRY;
}

void Phillosopher :: Eat()
{
    allow.lock();
    cout<<"Phillosopher "<<NamePhil<<" eating"<<endl;
    allow.unlock();
    sleep(1);
    allow.lock();
    cout<<"Phillosopher "<<NamePhil<<" end of eating"<<endl;
    allow.unlock();
    State=THINKING;
}

bool Phillosopher :: UpLeftFork()
{
    bool flag=false;
     Left.Fork_Mutex.lock();
    Waiter->ChekerMutex.lock();
    if(Waiter->StateFork[Left.Number]==-1)
        if(Waiter->Permission(Left.Number))
        {
            Waiter->StateFork[Left.Number]=NamePhil;
            flag=true;
        }
    Waiter->ChekerMutex.unlock();
    Left.Fork_Mutex.unlock();
    return flag;
}

bool Phillosopher :: UpRightFork()
{
    bool flag=false;
    Right.Fork_Mutex.lock();
    Waiter->ChekerMutex.lock();
    if(Waiter->StateFork[Right.Number]==-1)
        if(Waiter->Permission(Right.Number))
        {
            Waiter->StateFork[Right.Number]=NamePhil;
            flag=true;
        }
    Waiter->ChekerMutex.unlock();
    Right.Fork_Mutex.unlock();
    return flag;
}

void Phillosopher :: DownLeftFork()
{
    Left.Fork_Mutex.lock();
    Waiter->ChekerMutex.lock();
    Waiter->Returning();
    Waiter->StateFork[Left.Number]=-1;
    Waiter->ChekerMutex.unlock();
    Left.Fork_Mutex.unlock();
}

void Phillosopher :: DownRightFork()
{
    Right.Fork_Mutex.lock();
    Waiter->ChekerMutex.lock();
    Waiter->Returning();
    Waiter->StateFork[Right.Number]=-1;
    Waiter->ChekerMutex.unlock();
    Right.Fork_Mutex.unlock();
}

void Phillosopher :: run()
{
    while(true)
    {
        if(State==HUNGRY)
        {
            if(UpLeftFork())
            {
                if(UpRightFork())
                {
                    State=EATING;
                    Eat();
                    DownLeftFork();
                    DownRightFork();
                    continue;
                }
                else
                {
                    DownLeftFork();
                    continue;
                }
            }
            else
            {
                continue;
            }
        }
        else if(State==THINKING) Think();
    }
}
