#include <iostream>
#include <vector>
#include <queue>
#include <set>

using namespace std;

int N, M, V;
vector<set<int>> v;
vector<bool> dfsVisited;
queue<int> q;
vector<bool> bfsVisited;

void DFS(int start)
{
    cout << start << " ";

    dfsVisited[start] = true;

    for (int connect : v[start])
    {
        if (!dfsVisited[connect])
        {
            DFS(connect);
        }
    }
}

void BFS()
{
    while (!q.empty())
    {
        int start = q.front();
        q.pop();

        cout << start << " ";

        for (int idx : v[start])
        {
            if (!bfsVisited[idx])
            {
                bfsVisited[idx] = true;
                q.push(idx);
            }
        }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> V;

    v.resize(N + 1);
    dfsVisited.resize(N + 1, false);
    bfsVisited.resize(N + 1, false);

    int s, e;
    for (int i = 0; i < M; i++)
    {
        cin >> s >> e;
        v[s].insert(e);
        v[e].insert(s);
    }

    DFS(V);
    cout << "\n";
    
    q.push(V);
    bfsVisited[V] = true;
    BFS();
    cout << "\n";

    return 0;
}