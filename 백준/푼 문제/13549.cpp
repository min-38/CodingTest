#include <iostream>
#include <queue>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> dist(100000 + 1, 1e9);

    using P = pair<int,int>; // (현재까지의 거리, 현재 위치)
    priority_queue<P, vector<P>, greater<P>> pq;

    dist[N] = 0;
    pq.push({0, N});
    while (!pq.empty())
    {
        P p = pq.top(); pq.pop();
        if (p.second == K) break;

        if (p.second == K)
            break;

        // x * 2 이동 (비용 0)
        if (p.second * 2 <= 100000 && dist[p.second * 2] > p.first) {
            dist[p.second * 2] = p.first;
            pq.push({dist[p.second * 2], p.second * 2});
        }

        // x - 1 이동 (비용 1)
        if (p.second - 1 >= 0 && dist[p.second - 1] > p.first + 1) {
            dist[p.second - 1] = p.first + 1;
            pq.push({dist[p.second - 1], p.second - 1});
        }

        // x + 1 이동 (비용 1)
        if (p.second + 1 <= 100000 && dist[p.second + 1] > p.first + 1) {
            dist[p.second + 1] = p.first + 1;
            pq.push({dist[p.second + 1], p.second + 1});
        }
    }

    cout << dist[K] << endl;

    return 0;
}