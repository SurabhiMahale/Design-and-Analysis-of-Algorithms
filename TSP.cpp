#include <iostream>
using namespace std;
#define INF 999
#define MAXN 15

int N;
int dist[MAXN][MAXN];
int minCost = INF;
int minPath[MAXN];
bool visited[MAXN];
// u: the current node (city) being visited.
// level: the current level in the search tree (i.e., the number of cities already visited).
// cost: the current cost of the partial tour.
// path: an array that stores the current partial tour.
void tsp_bb(int u, int level, int cost, int path[])
{
    // If the current cost is already greater than or equal to the minimum cost found so far,stop searching further
    if (cost >= minCost)
    {
        return;
    }
    // If we have visited all the nodes, update the minimum cost and path if the current cos is less
    if (level == N)
    {
        cost += dist[u][0];
        if (cost < minCost)
        {
            minCost = cost;
            for (int i = 0; i < N; i++)
            {
                minPath[i] = path[i];
            }
        }
        return;
    }

    for (int v = 1; v < N; v++)
    {
        if (!visited[v])
        {
            visited[v] = true;
            path[level] = v;
            tsp_bb(v, level + 1, cost + dist[u][v], path);
            visited[v] = false;
        }
    }
}
int main()
{
    cout << "Enter number of cities: ";
    cin >> N;
    cout << "Enter adjacency matrix: \n";
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
            cin >> dist[i][j];

    int path[MAXN];
    path[0] = 0;

    for (int i = 1; i < N; i++)
        visited[i] = false;

    visited[0] = true;

    tsp_bb(0, 1, 0, path);

    cout << "Minimum Cost: " << minCost << endl;
    cout << "Path: ";
    for (int i = 0; i < N; i++)
        cout << minPath[i] << "->";

    cout << "0" << endl;
    return 0;
}
