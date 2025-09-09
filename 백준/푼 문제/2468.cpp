#include <iostream>
#include <vector>
#include <stack>

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

using namespace std;

int main()
{
    // 2차원 배열의 행과 열의 개수를 나타내는 수
    int N;
    cin >> N;

    int max = 0;
    int v[N][N];
    for (int i = 0; i < N; i++)
        for (int j = 0; j < N; j++)
        {
            cin >> v[i][j];
            if (max < v[i][j])
                max = v[i][j];
        }

    int result = 0;
    int rainAmount = 0; // 비 내리는 양
    while (rainAmount < max)
    {
        vector<vector<bool>> visited(N, vector<bool>(N, false));

        int safeAreaCnt = 0;
        for (int i = 0; i < N; i++)
            for (int j = 0; j < N; j++)
            {
                if (v[i][j] > rainAmount && !visited[i][j])
                {
                    stack<pair<int, int>> s; // y, x
                    s.push({i ,j});
                    visited[i][j] = true;
                    safeAreaCnt++;

                    while (!s.empty())
                    {
                        auto t = s.top();
                        s.pop();

                        int y = t.first;
                        int x = t.second;

                        for (int k = 0; k < 4; k++)
                        {
                            int newX = x + dx[k];
                            int newY = y + dy[k];

                            if (newX >= 0 && newX < N && newY >= 0 && newY < N && !visited[newY][newX] && v[newY][newX] > rainAmount)
                            {
                                s.push({newY, newX});
                                visited[newY][newX] = true;
                            }
                        }
                    }
                }
            }
        
        if (safeAreaCnt > result)
            result = safeAreaCnt;

        rainAmount++;
    }

    cout << result << "\n";

    return 0;
}