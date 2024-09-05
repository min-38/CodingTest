#include <limits>
#include <queue>
#include <vector>

using namespace std;

int solution(int N, vector<vector<int> > road, int K) {
    vector<pair<int, int>> graph[N + 1];
    vector<int> distances(N + 1, numeric_limits<int>::max());
    vector<bool> visited(N + 1, false);
    distances[1] = 0;
    
    // 방향이 따로 없으므로 양방향 동일한 가중치
    for(const auto &r : road) {
        int a = r[0], b = r[1], cost = r[2];
        graph[a].push_back({b, cost});
        graph[b].push_back({a, cost});
    }

    // 출발점을 heap에 추가
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push({0, 1});

    while(!heap.empty()) {
        int dist = heap.top().first;
        int node = heap.top().second;
        heap.pop();

        // 이미 방문한 노드는 무시
        if(visited[node])
            continue;
        visited[node] = true;

        for(const auto &next : graph[node]) {
            int next_node = next.first;
            int next_dist = next.second;
            int cost = dist + next_dist;

            // 거쳐가는 노드로 가는 경로의 비용이 더 짧으면 최소 비용 갱신
            if(cost < distances[next_node]) {
                distances[next_node] = cost;
                heap.push({cost, next_node});
            }
        }
    }
    
    int count = 0;

    // 거리가 K 이하인 장소를 카운트
    for(int i = 1; i<= N; i++)
        if(distances[i] <= K)
            count++;
    
    return count;
}