#include <string>
#include <vector>
#include <queue>

using namespace std;

struct Node {
    int num;
    int length = 0;
    vector<int> v;
};

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    vector<Node> nodes(n + 1);
    vector<bool> visited(n + 1, false);

    for(int i = 0; i < edge.size(); i++) {
        int left = edge[i][0], right = edge[i][1];

        nodes[left].num = left;
        nodes[right].num = right;

        nodes[left].v.push_back(right);
        nodes[right].v.push_back(left);
    }

    visited[1] = true;
    
    deque<int> q;
    q.push_back(1); // 시작은 1부터
    while(!q.empty()) {
        int nodeIdx = q.front();
        q.pop_front();

        for(int i = 0; i < nodes[nodeIdx].v.size(); i++)
            if(!visited[nodes[nodeIdx].v[i]]) {
                visited[nodes[nodeIdx].v[i]] = true;
                
                nodes[nodes[nodeIdx].v[i]].length = nodes[nodeIdx].length + 1;
                q.push_back(nodes[nodeIdx].v[i]);
            }
    }
    
    int max = -1;
    for(int i = 1; i <= n; i++)
        if(max <= nodes[i].length) {
            if(max == nodes[i].length) {
                answer++;
                continue;
            }
            max = nodes[i].length;
            answer = 1;
        }

    return answer;
}