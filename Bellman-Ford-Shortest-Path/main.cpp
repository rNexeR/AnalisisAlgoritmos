#include "Test.h"
#include <iostream>
#include <limits.h>
using namespace std;

int* getShortestPath(int** graph, int size, int origin)
{
    cout<<endl<<endl;
    int* distances = (int*)malloc(sizeof(int)*size);
    int* predecessor = (int*)malloc(sizeof(int)*size);

    for(uint i = 0; i < (uint)size; i++){
        distances[i] = INT_MAX;
        predecessor[i] = -1;
    }

    distances[origin] = 0;
    predecessor[origin] = 0;

    for(uint i = 0; i < (uint)size; i++){
        for(uint j = 0; j < (uint)size; j++){
            int w = graph[i][j];
            if(w == -1)
                continue;
            if(distances[i] + w < distances[j]){
                distances[j] = distances[i] + w;
                predecessor[j] = i;
            }
        }
    }

    for(uint i = 0; i < (uint)size; i++){
        cout<<predecessor[i]<<" ";
    }
    cout<<endl;
    
    return predecessor;
}

int main ()
{
    test();
    return 0;
}
