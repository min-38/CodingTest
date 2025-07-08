#include <iostream>
#include <vector>

using namespace std;

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};

void dfs(int x, int y, vector<int>& field, vector<bool>& visited, int M, int N)
{
    visited[y * M + x] = true;

    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && nx < M && ny >= 0 && ny < N && field[ny * M + nx] == 1 && !visited[ny * M + nx])
        {
            dfs(nx, ny, field, visited, M, N);
        }
    }
}

int main()
{
    int T;  // 테스트케이스
    cin >> T;

    for (int i = 0; i < T; i++)
    {
        int M, N, K;  // M: 가로, N: 세로, K: 배추 개수
        cin >> M >> N >> K;

        vector<int> field(M * N, 0);
        vector<bool> visited(M * N, false);

        for (int j = 0; j < K; j++)
        {
            int x, y;
            cin >> x >> y;
            field[y * M + x] = 1;
        }
        
        int result = 0;
        for (int j = 0; j < field.size(); j++)
        {
            if (field[j] == 1 && !visited[j])
            {
                dfs(j % M, j / M, field, visited, M, N);
                result++;
            }
        }

        cout << result << endl;
    }
    return 0;
}