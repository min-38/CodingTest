#include <iostream>
#include <queue>
using namespace std;

static int dx[] = {0, 1, 0, -1};
static int dy[] = {1, 0, -1, 0};

int A[101][101];
bool visited[101][101] = { false };
queue<pair<pair<int, int>, int>> q;

int N, M;
void BFS(int i, int j);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    for (int i = 1; i <= N; i++) {
        string s;
        cin >> s;
        for (int j = 1; j <= M; j++)
            A[i][j] = s[j - 1] - '0';
    }
    
    BFS(1, 1);

    return 0;
}

void BFS(int y, int x) { // BFS 구현
    q.push(make_pair(make_pair(y, x), 1));
    visited[y][x] = true;

    while (!q.empty())
    {
        int now_y = q.front().first.first;
        int now_x = q.front().first.second;
        int moved = q.front().second;
        q.pop();

        if (now_y == N && now_x == M)
        {
            cout << moved << endl;
            return;
        }

        for (int i = 0; i < 4; i++)
        {
            int new_y = now_y + dy[i];
            int new_x = now_x + dx[i];

            if (!visited[new_y][new_x] && A[new_y][new_x] == 1)
            {
                q.push(make_pair(make_pair(new_y, new_x), moved + 1));
                visited[new_y][new_x] = true;
            }
        }
    }
}
