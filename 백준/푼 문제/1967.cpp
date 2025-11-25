#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> tree[10001]; // 도착, 가중치
bool visited[10001];

int max_weight = 0;
int max_weight_node = 0;

void dfs(int node, int weight)
{
    visited[node] = true;

    if (weight > max_weight)
    {
        max_weight = weight;
        max_weight_node = node;
    }

    for (auto& next : tree[node])
    {
        int next_node = next.first; 
        int next_weight = next.second;

        if (!visited[next_node])
            dfs(next_node, weight + next_weight);
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    for (int i = 0; i < N - 1; i++)
    {
        int root, child, weight;
        cin >> root >> child >> weight;

        tree[child].push_back({root, weight});

        tree[root].push_back({child, weight});
        tree[child].push_back({root, weight});
    }

    dfs(N, 0);
    fill(visited, visited + 10001, false);
    dfs(max_weight_node, 0);

    cout << max_weight << '\n';

    return 0;
}
