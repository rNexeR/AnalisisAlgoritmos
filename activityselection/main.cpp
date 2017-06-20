#include "Test.h"
#include <iostream>
using namespace std;

vector<int> selectActivities(vector<int> start, vector<int> finish)
{
    vector<int> answer;
    answer.push_back(0);
    for(unsigned int i = 1; i < start.size(); i++)
        if(start[i] >= finish[answer[answer.size()-1]])
            answer.push_back(i);

    return answer;
}

int main ()
{
    test();
    return 0;
}
