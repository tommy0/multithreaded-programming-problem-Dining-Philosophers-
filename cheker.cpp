#include <cheker.h>
#include <setting.h>
#include <memory.h>

Cheker::Cheker()
{
    for(int i=0;i<AMOUNT_PHILLOSOPHERS;++i)
        StateFork[i]=-1;
    AmountFreeFork=AMOUNT_PHILLOSOPHERS;
}


bool Cheker::Permission(int fork)
{
    if((StateFork[fork]==-1) && (AmountFreeFork>1))
    {
        AmountFreeFork--;
        return true;
    }
    else return false;
}

void Cheker::Returning()
{
    AmountFreeFork++;
}
