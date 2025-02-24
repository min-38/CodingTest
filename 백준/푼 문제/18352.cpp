#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int N, M, K, X; // 도시의 개수, 도로의 개수, 거리 정보, 출발 도시의 번호
vector<vector<int>> A;
vector<int> B;
vector<int> visited;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M >> K >> X;

    A = vector<vector<int>>(N + 1);
    visited = vector<int>(N + 1, -1);

    for (int i = 0; i < M; i++)
    {
        int start, end;
        cin >> start >> end;
        A[start].push_back(end);
    }

    queue<int> q;
    q.push(X);
    visited[X] = 0;
    while (!q.empty())
    {
        int start = q.front();
        q.pop();

        for (int next : A[start])
        {
            if (visited[next] == -1)
            {
                visited[next] = visited[start] + 1;
                q.push(next);
            }
        }
    }

    for (int i = 1; i <= N; i++)
        if (visited[i] == K)
            B.push_back(i);
    
    if (B.empty())
        cout << -1 << endl;
    else
    {
        sort(B.begin(), B.end());
        for (int result : B)
            cout << result << "\n";
    }

    return 0;
}