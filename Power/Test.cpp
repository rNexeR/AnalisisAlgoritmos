#include "Test.h"

void evaluar()
{
    if(power(2, 3) == 8
       && power(7, 4) == 2401
       && power(45, 0) == 1
       && power(8, 5) == 32768
       && power(4, 1) == 4
       )
    {
        cout<<"Pass"<<endl;
    }else
    {
        cout<<"Fail"<<endl;
    }

}
