#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N; // 노드의 개수

    vector<vector<int>> v(N + 1);

    vector<bool> visited(N + 1, false);
    visited[1] = true;

    vector<int> result(N + 1, 0);

    for (int i = 1; i < N; i++)
    {
        int node1, node2;
        cin >> node1 >> node2;

        v[node1].push_back(node2);
        v[node2].push_back(node1);
    }

    stack<int> s;
    s.push(1);

    while (!s.empty())
    {
        int top = s.top();
        s.pop();

        for (int next : v[top])
        {
            if (!visited[next])
            {
                result[next] = top;
                s.push(next);
                visited[next] = true;
            }
        }
    }

    for (int i = 2; i <= N; i++)
        cout << result[i] << "\n";

    
    return 0;
}