#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<bool> visited;

void dfs(int node, int length, string result)
{
    if (length == M)
    {
        cout << result << "\n";
        return;
    }

    for (int i = 1; i <= N; i++)
        if (!visited[i])
        {
            visited[i] = true;
            dfs(i, length + 1, result + " " + to_string(i));
            visited[i] = false;
        }
}

int main()
{
    cin >> N >> M;

    visited.assign(N + 1, false);

    for (int root = 1; root <= N; root++)
    {
        visited[root] = true;
        dfs(root, 1, to_string(root));
        visited[root] = false;
    }

    return 0;
}