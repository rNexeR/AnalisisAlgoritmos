#include "Test.h"
#include <iostream>
#include <limits>
using namespace std;

int* getShortestPath(int** graph, int size, int origin)
{
  int* predecessor = new int[size];
  int* distance = new int[size];
  for (int i = 0; i < size; ++i)
  {
    predecessor[i] = -1;
    distance[i] = std::numeric_limits<int>::max();
  }
  predecessor[origin] = 0;
  distance[origin] = 0;

  for (int i = 0; i < size; ++i)
  {
    for (int j = 0; j < size; ++j)
    {
      if(i!=j && graph[i][j]!=-1 && (distance[i] + graph[i][j] < distance[j]))
      {
        distance[j] = distance[i] + graph[i][j];
        predecessor[j] = i;
      }
    }
  }

  return predecessor;
}


bool pathExists(int** graph, int size, int source, int destination)
{
  cout<<"entro "<<source<<" d "<<destination<<endl;
  int * path = getShortestPath(graph, size, source);
  for(int i = 0; i < size; i++)
    cout<<path[i]<<" en "<<i<<endl;
  cout<<"retorning "<<(path[destination] != -1)<<endl;
  int current = destination;
  while((path[current] != -1) && path[current] != source){
    //predecessor = current;
    current = path[current];
  }
  return path[current] == source;
  //return (path[destination] != -1) && path[path[destination]] != -1;
}

int main ()
{
    test();
    return 0;
}
