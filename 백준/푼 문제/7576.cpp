#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int M, N;
    cin >> M >> N;

    
    int zero_cnt = 0;
    vector<vector<int>> storage(N, vector<int>(M));
    vector<int> visited(N * M, 0);
    queue<pair<int, int>> q; // (y, x)

    for (int i = 0; i < N; i++)
        for (int j = 0; j < M; j++)
        {
            cin >> storage[i][j];

            if (storage[i][j] == 0)
                zero_cnt++;
            else if (storage[i][j] == 1)
            {
                q.push({i, j});
                visited[i * M + j] = 1;
            }
                
        }

    if (zero_cnt == 0)
    {
        cout << "0" << endl;
        return 0;
    }

    while (!q.empty())
    {
        auto a = q.front();
        q.pop();

        for (int i = 0; i < 4; i++)
        {
            int nx = a.second + dx[i];
            int ny = a.first + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
        
            if (storage[ny][nx] == 0)
            {
                storage[ny][nx] = 1;
                --zero_cnt;
                
                q.push({ny, nx});
                visited[ny * M + nx] = visited[a.first * M + a.second] + 1;
            }
            else if (storage[ny][nx] == 1)
            {
                int nday = visited[a.first * M + a.second] + 1;
                if (nday < visited[ny * M + nx])
                {
                    visited[ny * M + nx] = nday;
                    q.push({ny, nx});
                }
            }
        }
    }

    if (zero_cnt > 0)
        cout << -1 << endl;
    else
    {
        sort(visited.rbegin(), visited.rend());
        cout << visited[0] - 1 << endl;
    }


    return 0;
}