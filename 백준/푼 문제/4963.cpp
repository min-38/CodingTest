#include <iostream>
#include <vector>
#include <stack>

using namespace std;

const int dx[] = {0, 0, -1, 1, -1, 1, -1, 1};
const int dy[] = {-1, 1, 0, 0, -1, -1, 1, 1};

int main()
{
    ios::sync_with_stdio(false);
    cout.tie(NULL);
    cin.tie(NULL);

    while (true)
    {
        int w, h;
        cin >> w >> h;

        if (w == 0 && h == 0)
            break;

        vector<vector<int>> world(h, vector<int>(w));
        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                cin >> world[i][j];
            }
        }

        vector<bool> visited(h * w, false);
        int result = 0;

        for (int i = 0; i < h; i++)
        {
            for (int j = 0; j < w; j++)
            {
                int idx = i * w + j;
                if (world[i][j] == 1 && !visited[i * w + j])
                {
                    visited[idx] = true;
                    result++;

                    stack<pair<int, int>> s;
                    s.push({i, j}); // y, x

                    while (!s.empty())
                    {
                        auto t = s.top();
                        s.pop();

                        int y = t.first;
                        int x = t.second;

                        for (int k = 0; k < 8; k++)
                        {
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            int newIdx = newY * w + newX;

                            if (newX >= 0 && newX < w && newY >= 0 && newY < h && world[newY][newX] == 1 && !visited[newIdx])
                            {
                                s.push({newY, newX});
                                visited[newIdx] = true;
                            }
                        }
                    }
                }
            }
        }
        cout << result << endl;
    }
    return 0;
}