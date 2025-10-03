#include <iostream>
#include <vector>
#include <queue>

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
    vector<int> visited(N * M, -1);
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
                visited[i * M + j] = 0;
            }
                
        }

    if (zero_cnt == 0)
    {
        cout << 0 << '\n';
        return 0;
    }

    int max_day = 0;

    while (!q.empty())
    {
        auto a = q.front();
        q.pop();

        int cy = a.first;
        int cx = a.second;
        int curd = visited[cy * M + cx];


        for (int i = 0; i < 4; i++)
        {
            int nx = cx + dx[i];
            int ny = cy + dy[i];

            if (nx < 0 || nx >= M || ny < 0 || ny >= N)
                continue;
        
            if (storage[ny][nx] == 0 && visited[ny * M + nx] == -1)
            {
                storage[ny][nx] = 1;
                --zero_cnt;

                visited[ny * M + nx] = curd + 1;
                max_day = max(max_day, curd + 1);

                q.push({ny, nx});
            }
        }
    }

    if (zero_cnt > 0)
        cout << -1 << "\n";
    else
    {
        cout << max_day << '\n';
    }


    return 0;
}