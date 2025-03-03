#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;  // 건물 종류 수
    cin >> N;

    vector<vector<int>> V(N + 1);
    vector<int> times(N + 1, 0);
    vector<int> indegrees(N + 1, 0);
    vector<int> results(N + 1, 0);

    for (int i = 1; i <= N; i++)
    {
        cin >> times[i];

        while (true)
        {
            int A = 0;
            cin >> A;
            if (A == -1)
                break;
            V[A].push_back(i);
            indegrees[i]++;
        }
    }

    queue<int> q;
    for (int i = 1; i <= N; i++)
        if (indegrees[i] == 0)
            q.push(i);

    while (!q.empty())
    {
        int node = q.front();
        q.pop();

        int time = results[node];
        for (int connect : V[node])
        {
            indegrees[connect]--;
            results[connect] = max(results[connect], results[node] + times[node]);

            if (indegrees[connect] == 0)
                q.push(connect);
        }
    }

    for (int i = 1; i <= N; i++)
        cout << results[i] + times[i] << "\n";

    return 0;
}
