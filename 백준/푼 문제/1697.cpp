#include <iostream>
#include <queue>

using namespace std;

bool visited[100001] = { false, };

void BFS(const int N, const int K) {
    queue<pair<int, int>> q;
    q.push({N, 0});

    visited[N] = true;

    int n;
    while (!q.empty()) {
        int n = q.front().first;
        int time = q.front().second;
        q.pop();

        if (n == K) {
            cout << time << "\n";
            break;
        }

        time++;

        if (n - 1 >= 0 && n - 1 <= 100001)
            if (!visited[n - 1]) {
                q.push({ n - 1, time });
                visited[n - 1] = true;
            }

        if (n + 1 >= 0 && n + 1 <= 100001)
            if (!visited[n + 1]) {
                q.push({ n + 1, time });
                visited[n + 1] = true;
            }

        if (n * 2 >= 0 && n * 2 <= 100001)
            if (!visited[n * 2]) {
                q.push({ n * 2, time });
                visited[n * 2] = true;
            }
    }
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;
    int N, K;
    cin >> N >> K;

    BFS(N, K);

    return 0;
}
