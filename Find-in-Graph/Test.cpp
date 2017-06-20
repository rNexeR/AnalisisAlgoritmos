#include "Test.h"

int** _initGraph(int size)
{
    int **answer = new int* [size];
    for(int i=0;i<size;i++)
    {
        answer[i]=new int[size];
        for(int j=0;j<size;j++)
        {
            answer[i][j]=-1;
        }
    }
    return answer;
}

void test()
{
    int** g1 = _initGraph(5);
    g1[0][1]=99;
    g1[0][2]=50;
    g1[1][2]=50;
    g1[1][3]=50;
    g1[1][4]=50;
    g1[2][3]=99;
    g1[3][4]=75;

    if(pathExists(g1, 5, 0, 1)
       && pathExists(g1, 5, 0, 1)
       && pathExists(g1, 5, 0, 4)
       && !pathExists(g1, 5, 3, 0)
       && !pathExists(g1, 5, 4, 2)
       )
    {
        cout<<"Test: Pass"<<endl;
    }else
    {
        cout<<"Test: Fail"<<endl;
    }

}
