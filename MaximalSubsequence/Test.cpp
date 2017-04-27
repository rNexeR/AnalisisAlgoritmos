#include "Test.h"

void test()
{
    int arr1[] = { -2, -5, 6, -2, -3, 1, 5, -6};
    std::vector<int> v1( arr1, arr1+8 );

    int arr2[] = { -3, 4, 2, 2, -2, 1};
    std::vector<int> v2( arr2, arr2+6 );

    int arr3[] = { -2, 5, -2, 3, -4, 3, 5};
    std::vector<int> v3( arr3, arr3+7 );

    if(maxSequenceSum(v1) == 7
       && maxSequenceSum(v2) == 8
       && maxSequenceSum(v3) == 10
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
