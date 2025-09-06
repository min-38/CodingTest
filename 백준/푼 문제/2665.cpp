#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <limits>

using namespace std;

const int dy[4] = {-1,1,0,0};
const int dx[4] = {0,0,-1,1};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n; 
    cin >> n;
    
    vector<string> map(n);
    for (int i = 0; i < n; ++i)
        cin >> map[i];

    const int INF = 1e9;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    dist[0][0] = 0;

    deque<pair<int,int>> dq;
    dq.push_front({0, 0});

    while (!dq.empty()) {
        auto t = dq.front();
        dq.pop_front();

        int curX = t.first;
        int curY = t.second;

        for (int i = 0; i < 4; i++) {
            int nextX = curX + dx[i];
            int nextY = curY + dy[i];

            if (nextX >= 0 && nextX < n && nextY >= 0 && nextY < n)
            {
                int w = (map[nextY][nextX] == '0') ? 1 : 0; 
                if (dist[nextY][nextX] > dist[curY][curX] + w)
                {
                    dist[nextY][nextX] = dist[curY][curX] + w;

                    if (w == 0)
                        dq.push_front({nextX, nextY});
                    else
                        dq.push_back({nextX, nextY});
                }
            }
        }
    }
    cout << dist[n - 1][n - 1] << "\n";
}