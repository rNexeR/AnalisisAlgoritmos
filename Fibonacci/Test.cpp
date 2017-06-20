#include "Test.h"

void test()
{
    if(fibonacci(5)==5
       && fibonacci(8)==21
       && fibonacci(1)==1
       && fibonacci(2)==1
       && fibonacci(3)==2
       && fibonacci(4)==3
       && fibonacci(20)==6765
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
