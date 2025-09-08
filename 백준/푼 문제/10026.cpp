#include <iostream>
#include <vector>
#include <stack>

using namespace std;

vector<string> v;
vector<vector<bool>> visited;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    v = vector<string>(N, "");
    visited = vector<vector<bool>>(N, vector<bool>(N, false));

    for(int i = 0; i < N; i++)
        cin >> v[i];

    int cnt1 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                cnt1++;
                stack<pair<int, int>> s;
                s.push({i, j});

                while (!s.empty())
                {
                    auto t = s.top();
                    s.pop();

                    int y = t.first;
                    int x = t.second;
                    char color = v[y][x];

                    visited[y][x] = true;

                    for (int k = 0; k < 4; k++)
                    {
                        int nextX = x + dx[k];
                        int nextY = y + dy[k];

                        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visited[nextY][nextX])
                        {
                            char nextColor = v[nextY][nextX];

                            if (color == nextColor)
                                s.push({nextY, nextX});
                        }
                    }
                }
            }
        }
    }

    visited = vector<vector<bool>>(N, vector<bool>(N, false));
    int cnt2 = 0;
    for (int i = 0; i < N; i++)
    {
        for (int j = 0; j < N; j++)
        {
            if (!visited[i][j])
            {
                cnt2++;
                stack<pair<int, int>> s;
                s.push({i, j});

                while (!s.empty())
                {
                    auto t = s.top();
                    s.pop();

                    int y = t.first;
                    int x = t.second;
                    char color = v[y][x];

                    visited[y][x] = true;

                    for (int k = 0; k < 4; k++)
                    {
                        int nextX = x + dx[k];
                        int nextY = y + dy[k];

                        if (nextX >= 0 && nextX < N && nextY >= 0 && nextY < N && !visited[nextY][nextX])
                        {
                            char nextColor = v[nextY][nextX];

                            if (color == nextColor || (color == 'R' && nextColor == 'G') || (color == 'G' && nextColor == 'R'))
                                s.push({nextY, nextX});
                        }
                    }
                }
            }
        }
    }

    cout << cnt1 << " " << cnt2 << endl;

    return 0;
}
