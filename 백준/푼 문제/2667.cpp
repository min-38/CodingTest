#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector<bool> visited;
vector<string> map;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int y, int x, int& count)
{
    visited[y * N + x] = true;
    count += 1;

    for (int i = 0; i < 4; i++)
    {
        int ny = y + dy[i];
        int nx = x + dx[i];
        if (ny >= 0 && ny < N && nx >= 0 && nx < N && map[ny][nx] == '1' && !visited[ny * N + nx])
            dfs(ny, nx, count);
    }
}

int main()
{
    cin >> N;

    map = vector<string>(N, "");
    visited = vector<bool>(N * N, false);

    vector<int> results;

    for (int i = 0; i < N; i++)
        cin >> map[i];

    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            if (map[i][j] == '1' && !visited[i * N + j])
            {
                int count = 0;
                dfs(i, j, count);

                results.push_back(count);
            }
        }

    cout << results.size() << endl;
    sort(results.begin(), results.end());

    for (int result : results)
        cout << result << endl;
    
    return 0;
}