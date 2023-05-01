#include <bits/stdc++.h>
using namespace std;
#define INF 999

int V, src, cost[100][100];
int dist[100];
bool visited[100] = {0};
int parent[100];

void init()
{
    for (int i = 0; i < V; i++)
    {
        dist[i] = INF;
        parent[i] = i;
    }
    dist[src] = 0;
}

// returns the index of the unvisited vertex with the smallest distance from the source vertex. 
int getNearest()
{
    int minvalue = INF;
    int minnode = 0;

    for (int i = 0; i < V; i++)
    {
        if (!visited[i] && dist[i] < minvalue)
        {
            minvalue = dist[i];
            minnode = i;
        }
    }
    return minnode;
}

void dijkstra()
{
    int visitedNodes = 0;

    while (visitedNodes < V) // loop until all nodes have been visited
    {
        int nearest = getNearest();
        visited[nearest] = true;    //marks the nearest node as visited.
        visitedNodes++; // increment the counter

        for (int adj = 0; adj < V; adj++)       //iterates over all the adjacent nodes of the nearest node.
        {
            if (cost[nearest][adj] != INF && dist[adj] > dist[nearest] + cost[nearest][adj])    //checks if the distance to the adj node through the nearest node is shorter than the current distance stored in dist[adj].
            {
                dist[adj] = dist[nearest] + cost[nearest][adj];
                parent[adj] = nearest;
            }
        }
    }
}
void display()
{
    cout << "Node:\t\t\tCost :\t\t\tPath\n";
    for (int i = 0; i < V; i++)
    {
        if (i != src)
        {
            cout << i << "\t\t\t" << dist[i] << "\t\t\t";
            cout << i;

            int parnode = parent[i];

            while (parnode != src)
            {
                cout << " <- " << parnode;
                parnode = parent[parnode];
            }
            cout << " <- " << src << endl;
        }
    }
}

int main()
{
    cout << "number of vertices:";
    cin >> V;

    for (int i = 0; i < V; i++)  
        for (int j = 0; j < V; j++)
            cin >> cost[i][j];
    
    cout << "src node: ";
    cin >> src;
    
    init();
    dijkstra();
    display();
    return 0;
}