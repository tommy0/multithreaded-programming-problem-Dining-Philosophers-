#include <QCoreApplication>
#include <QThread>
#include <iostream>
#include <phillosofer.h>
#define AMOUNT_PHILLOSOPHER 5
#define THINKING 0
#define HUNGRY 1
#define EATING 2

using namespace std;

int distrib(int i)
{
    if(i+1>(AMOUNT_PHILLOSOPHER-1)) return 0;
    else return (i+1);
}

int main(int argc, char *argv[])
{
    int i;
    Cheker MainCheker;
    Phillosopher **society = new Phillosopher*[AMOUNT_PHILLOSOPHER];
    for(i=0;i<AMOUNT_PHILLOSOPHER;++i)
    {
        society[i]= new Phillosopher(i,HUNGRY,distrib(i),i,&MainCheker);
    }
    for(int i=0; i<AMOUNT_PHILLOSOPHER;++i)
    {
        society[i]->start();
    }
    QCoreApplication a(argc, argv);
    return a.exec();
}
