#include <iostream>
#include <string>
#include <vector>
#include <climits>
#include <deque>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    int y1, x1, y2, x2;
    cin >> y1 >> x1 >> y2 >> x2;

    vector<string> map(N, "");
    for (int i = 0; i < N; i++)
        cin >> map[i];

    deque<pair<pair<int, int>, int>> q; // x, y
    q.push_front({{x1 - 1, y1 - 1}, 0});

    vector<int> visited(N * M, INT_MAX);
    visited[(y1 - 1) * M + (x1 - 1)] = 0;

    int result = 0;
    while (!q.empty())
    {
        auto t = q.front();
        q.pop_front();

        int curX = t.first.first;
        int curY = t.first.second;
        int jumped = t.second;

        if (curX == x2 - 1 && curY == y2 - 1)
        {
            result = jumped;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX >= 0 && nextX < M && nextY >= 0 && nextY < N)
            {
                int newJump = jumped + (map[nextY][nextX] != '0');
                if (visited[nextY * M + nextX] > newJump)
                {
                    visited[nextY * M + nextX] = newJump;
                    if (map[nextY][nextX] == '1')
                        q.push_back({{nextX, nextY}, newJump});
                    else
                        q.push_front({{nextX, nextY}, newJump});
                }
            }
        }
    }

    cout << result << endl;

    return 0;
}