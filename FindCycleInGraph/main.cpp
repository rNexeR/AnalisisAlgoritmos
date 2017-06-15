#include "Test.h"
#include <iostream>
#include <map>

using namespace std;

// bool **generateCheckedGraph(int size)
// {
//     bool **checked = new bool *[size];
//     for (int i = 0; i < size; i++)
//     {
//         checked[i] = new bool[size];
//         memset(checked[i], 0, size);
//     }
//     return checked;
// }

map<int, bool> checked;

bool isInMap(string key, map<int, bool> mapa)
{
    map<int, bool>::iterator it = mapa.find(key);
    return it != mapa.end();
}

int get_next_edge(int **graph, int size, int row, int start){
    for (int i = start; i < size; i++)
    {
        if(graph[row][i] != -1)
            return i;
    }
    return -1;
}

bool check_node(int **graph, int size, int node_pos)
{
    if (isInMap(node_pos, checked))
        return false;
    else
    {
        checked[node_pos] = true;
        int next_edge = get_next_edge(graph, size, node_pos, 0);
        check_node();
    }
}

bool hasCycle(int **graph, int size)
{
    // bool **checked = generateCheckedGraph(size);
    int y = -1;

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size; j++)
        {
            if (graph[i][j] != -1)
            {
                y = i;
                break;
            }
        }
    }

    if (y == -1)
        return false;

    return check_node(graph, size, y);
}

int main()
{
    test();
    return 0;
}
