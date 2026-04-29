#include <iostream>
#include<vector>
using namespace std;

bool dfs(int v, vector<vector<int>> &adj, vector<bool> &visited, int parent)
{
    visited[v] = true;
    for (int i : adj[v])
    {
        if (!visited[i])
        {
            if (dfs(i, adj, visited, v))
                return true;
        }
        else if (i != parent)
            return true;
    }

    return false;
}
bool isCycle(vector<vector<int>> &adj)
{
    int V= adj.size();
    vector<bool> visited(V, false);

    for (int u = 0; u < V; u++)
    {
        if (!visited[u])
        {
            if (dfs(u, adj, visited, -1))
                return true;
        }
    }

    return false;
}

int main()
{
    vector<vector<int>> adj = {{1, 2}, {0, 2}, {0, 1, 3}, {2}};
    isCycle(adj) ? cout << "true" : cout << "false";

    return 0;

}
