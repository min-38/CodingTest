#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<int>> A;
vector<int> B;
vector<bool> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 컴퓨터 개수, 신뢰 관계 수
    cin >> N >> M;

    A = vector<vector<int>>(N + 1);
    B = vector<int>(N + 1);
    visited = vector<bool>(N + 1);

    for (int i = 0; i < M; i++)
    {
        int s, e;
        cin >> s >> e;
        A[s].push_back(e);
    }

    int max = 0;
    for (int i = 1; i <= N; i++)
    {
        fill(visited.begin(), visited.end(), false);
        
        queue<int> q;
        q.push(i);
        visited[i] = true;
        while (!q.empty())
        {
            int node = q.front();
            q.pop();

            for (int next : A[node])
            {
                if (!visited[next])
                {
                    visited[next] = true;
                    ++B[next];
                    q.push(next);

                    if (B[next] > max)
                        max = B[next];
                }
            }
        }
    }

    for (int i = 1; i <= N; i++)
        if (B[i] == max)
            cout << i << " ";
    cout << "\n";

    return 0;
}