#include "Test.h"

void test()
{
    vector<int> v1;
    srand(time(NULL));
    for(int i=0;i<10;i++)
    {
        v1.push_back(rand()%100);
    }

    bool is_sorted = true;

    v1 = sort(v1);

    for(int i=1;i<(int)v1.size();i++)
        if(v1[i]<v1[i-1])
            is_sorted = false;

    if(v1.size()==10 && is_sorted)
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
