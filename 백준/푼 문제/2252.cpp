#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<vector<int>> V(N + 1);
    vector<int> indegrees(N + 1, 0);

    for (int i = 0; i < M; i++)
    {
        int A, B;
        cin >> A >> B;
        V[A].push_back(B);
        indegrees[B]++;
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (indegrees[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        cout << node << " ";

        for (int connect : V[node])
        {
            indegrees[connect]--;
            if (indegrees[connect] == 0)
                q.push(connect);
        }
    }

    cout << "\n";

    return 0;
}
