#include "Test.h"

void test()
{
    static const int s1[] = {10, 12, 20};
    static const int f1[] = {20, 25, 30};
    vector<int> vs1 (s1, s1 + sizeof(s1) / sizeof(s1[0]) );
    vector<int> vf1 (f1, f1 + sizeof(f1) / sizeof(f1[0]) );

    vector<int> res1 = selectActivities(vs1,vf1);

    static const int s2[] =  {1, 3, 0, 5, 8, 5};
    static const int f2[] =  {2, 4, 6, 7, 9, 9};

    vector<int> vs2 (s2, s2 + sizeof(s2) / sizeof(s2[0]) );
    vector<int> vf2 (f2, f2 + sizeof(f2) / sizeof(f2[0]) );

    vector<int> res2 = selectActivities(vs2,vf2);

    if(res1.size()==2
       && res1[0]==0
       && res1[1]==2
       && res2.size()==4
       && res2[0]==0
       && res2[1]==1
       && res2[2]==3
       && res2[3]==4
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
