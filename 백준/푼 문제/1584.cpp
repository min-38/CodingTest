#include <iostream>
#include <vector>
#include <deque>
#include <climits>

using namespace std;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

const int mapSize = 501;

vector<vector<int>> map(mapSize, vector<int>(mapSize, 0));

void setting(int value)
{
    int N; // 혹은 M
    cin >> N;

    for (int i = 0; i < N; i++)
    {
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;

        for (int j = min(y1, y2); j <= max(y1, y2); j++)
            for (int k = min(x1, x2); k <= max(x1, x2); k++)
                map[j][k] = value;
    }
}

int main()
{
    setting(1);
    setting(2);

    deque<pair<pair<int, int>, int>> dq;
    dq.push_front({{0, 0}, 0});  // x, y
    
    vector<int> lifes(mapSize * mapSize, INT_MAX);
    lifes[0] = 0;

    int result = -1;
    while (!dq.empty())
    {
        auto t = dq.front();
        dq.pop_front();

        int x = t.first.first;
        int y = t.first.second;
        int life = t.second;

        if (x == mapSize - 1 && y == mapSize - 1)
        {
            result = life;
            break;
        }

        for (int i = 0; i < 4; i++)
        {
            int nextX = x + dx[i];
            int nextY = y + dy[i];

            if (nextX >= 0 && nextX < mapSize && nextY >= 0 && nextY < mapSize)
            {
                // 죽음의 영역이면 가지 않음
                if (map[nextY][nextX] == 2)
                    continue;
                
                int newLife = life + (map[nextY][nextX] == 1);

                if (lifes[nextY * mapSize + nextX] > newLife)
                {
                    lifes[nextY * mapSize + nextX] = newLife;

                    if (map[nextY][nextX] == 1)
                        dq.push_back({{nextX, nextY}, newLife});
                    else
                        dq.push_front({{nextX, nextY}, newLife});
                }
            }
        }

    }

    cout << result << endl;

    return 0;
}