#include <iostream>
#include <vector>

using namespace std;

int node_cnt, edge_cnt;

vector<vector<int>> v;
vector<bool> visited;

void DFS(const int target)
{
    if (!visited[target])
    {
        visited[target] = true;
        for (int j = 0; j < v[target].size(); j++)
            DFS(v[target][j]);
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> node_cnt >> edge_cnt;

    v.resize(node_cnt + 1);
    visited.resize(node_cnt + 1, false);

    int a, b;
    for (int i = 0; i < edge_cnt; i++)
    {
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    int result = 0;
    for (int i = 1; i <= node_cnt; i++)
    {
        if (!visited[i])
        {
            DFS(i);
            result++;
        }
    }

    cout << result << "\n";

    return 0;
}