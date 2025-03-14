#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 도시의 개수, 버스의 개수
    cin >> N >> M;

    vector<vector<edge>> v(N + 1);
    vector<vector<int>> dm(N + 1, vector<int>(N + 1));
    vector<bool> visited(N + 1, false);

    for (int i = 0; i < M; i++)
    {
        int start, end, weight;
        cin >> start >> end >> weight;
        v[start].push_back(make_pair(end, weight));
    }

    int start, end;
    cin >> start >> end;

    vector<int> dist(N + 1, INT_MAX);
    priority_queue<edge, vector<edge>, greater<edge>> pq;
    pq.push({0, start});
    
    dist[start] = 0;
    while (!pq.empty())
    {
        edge node = pq.top();
        pq.pop();
        
        if (!visited[node.second])
        {
            visited[node.second] = true;
            for (edge next : v[node.second])
                if (!visited[next.first])
                    if (dist[next.first] > dist[node.second] + next.second)
                    {
                        dist[next.first] = dist[node.second] + next.second;
                        pq.push(make_pair(dist[next.first], next.first));
                    }
        }
    }

    cout << dist[end] << "\n";

    return 0;
}