#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>

using namespace std;

typedef pair<int, int> edge;

int main() {
    ios::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);

    int V, E, K; // 노드 개수, 에지 개수, 출발 노드의 번호
    cin >> V >> E >> K;

    vector<vector<edge>> arr(V + 1);

    for (int i = 0; i < E; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        arr[u].push_back({v, w});
    }

    priority_queue<edge, vector<edge>, greater<edge>> pq;
    vector<int> result(V + 1, INT_MAX);
    vector<bool> visited(V + 1, false);
    
    result[K] = 0;
    pq.push({0, K});

    while (!pq.empty())
    {
        edge ce = pq.top();
        pq.pop();

        if (visited[ce.second])
            continue;
        visited[ce.second] = true;

        for(int i = 0; i < arr[ce.second].size(); i++)
        {
			int next = arr[ce.second][i].first;
			int value = arr[ce.second][i].second;
			
			if(ce.first + value < result[next]){
				result[next] = ce.first + value;
				pq.push(make_pair(result[next], next));
			}
		}
    }

    for (int i = 1; i <= V; i++)
    {
        if (visited[i])
            cout << result[i] << "\n";
        else
            cout << "INF" << "\n";
    }

    return 0;
}