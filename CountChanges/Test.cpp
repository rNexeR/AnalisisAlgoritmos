#include "Test.h"

int _getSum(vector<int> vec)
{
    int sum=0;
    for(int i=0;i<(int)vec.size();i++)
    {
        sum+=vec[i];
    }
    return sum;
}

bool _contains(vector<int> container, vector<int> contained)
{
    for(int i=0;i<(int)container.size();i++)
    {
        bool flag = false;
        for(int j=0;j<(int)contained.size();j++)
        {
            if(container[i]==contained[j])
            {
                flag = true;
                break;
            }
        }
        if(!flag)
            return false;
    }
    return true;
}

void test()
{
    static const int arr[] = {1,2,3};
    vector<int> vec (arr, arr + sizeof(arr) / sizeof(arr[0]) );

    static const int arr2[] = {2, 5, 3, 6};
    vector<int> vec2 (arr2, arr2 + sizeof(arr2) / sizeof(arr2[0]) );

    if(countSolutions(vec, 4) == 4
        && countSolutions(vec2, 10) == 5
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
