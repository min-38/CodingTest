#include <vector>
#include <cmath>
#include <algorithm>
#include <climits>

using namespace std;

int dfs(int node, int parent, const vector<vector<int>>& graph) {
    int cnt = 1;
    // 인접 노드에 깊이 우선 탐색 계속 진행
    for(int child : graph[node])
        // 무한 탐색을 방지하기 위해 인접한 노드 중 부모 노드는 탐색하지 않음
        if(child != parent)
            cnt += dfs(child, node, graph);
    
    return cnt;
}

int solution(int n, vector<vector<int>> wires) {
    vector<vector<int>> graph(n + 1);
    // wire 정보를 활용해서 그래프 구축
    for(auto &wire : wires) {
        int a = wire[0];
        int b = wire[1];
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    
    int min_diff = INT_MAX;
    for(auto &wire : wires) {
        int a = wire[0];
        int b = wire[1];

        // 특정 전선 임시 삭제
        graph[a].erase(remove(graph[a].begin(), graph[a].end(), b), graph[a].end());
        graph[b].erase(remove(graph[b].begin(), graph[b].end(), a), graph[b].end());

        // 전력망을 단절하고 각 전력망의 송전탑 개수의 차이를 구함
        int cnt_a = dfs(a, b, graph);
        int cnt_b = n - cnt_a;

        // 현재 송전탑 개수 차이의 절댓값의 최솟값과 현재 값 중 더 적은 값을 택함
        min_diff = min(min_diff, abs(cnt_a - cnt_b));

        // 임시로 제거했던 전선을 복구
        graph[a].push_back(b);
        graph[b].push_back(a);
    }
    return min_diff;
}