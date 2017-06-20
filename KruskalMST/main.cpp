#include "Test.h"
#include <iostream>
#include <cstring>
#include "Edge.h"

using namespace std;

int s_o_int = sizeof(int);

bool graph_has_cycle_r(int **graph, int size, int *checks, int previous, int current)
{

    if (current >= size)
        return false;

    checks[current] = 1;

    for (int i = 0; i < size; i++)
    {
        if (i == current || i == previous)
            continue;

        if (graph[current][i] == -1)
            continue;

        if (checks[i] != 0)
            return true;

        if (graph_has_cycle_r(graph, size, checks, current, i))
            return true;
    }

    return false;
}

bool graph_has_cycle(int **graph, int size)
{
    int *checks = new int[size];
    memset(checks, 0, size * s_o_int);
    return graph_has_cycle_r(graph, size, checks, 0, 0);
}

void graph_set_value(int **graph, int size, Edge *edge)
{
    graph[edge->source][edge->destination] = edge->weight;
    graph[edge->destination][edge->source] = edge->weight;
}

int **getKruskalMST(int **graph, int size, vector<Edge *> edges)
{
    int **new_graph = new int *[size];
    for (int i = 0; i < size; i++)
    {
        new_graph[i] = new int[size];
        memset(new_graph[i], -1, size * s_o_int);
    }

    for (int i = 0; i < edges.size(); i++)
    {
        graph_set_value(new_graph, size, edges[i]);
        if (graph_has_cycle(new_graph, size))
        {
            edges[i]->weight = -1;
            graph_set_value(new_graph, size, edges[i]);
        }
    }
    return new_graph;
}

int main()
{
    test();
    return 0;
}
