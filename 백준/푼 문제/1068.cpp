#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> tree(51, vector<int>());
vector<bool> visited(51, false);

int node_cnt = 0;
int cut_node;

void dfs(int node)
{
    visited[node] = true;

    int possible_node = 0;

    for (int neighbor : tree[node])
    {
        if (neighbor == cut_node)
            continue;

        if (!visited[neighbor])
        {
            possible_node++;
            dfs(neighbor);
        }
    }

    if (possible_node == 0)
        node_cnt++;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    int root = -1;
    for (int i = 0; i < N; i++)
    {
        int num;
        cin >> num;

        // root node
        if (num == -1)
        {
            root = i;
            continue;
        }

        tree[num].push_back(i);
    }

    cin >> cut_node;

    if (cut_node != root)
        dfs(root);

    cout << node_cnt << "\n";

    return 0;
}
