#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int V;
vector<vector<pair<int, int>>> tree;

pair<int, int> dfs(int startNode) {
    int maxDist = 0;
    int farthestNode = startNode;

    stack<pair<int, int>> s;
    s.push({startNode, 0});

    vector<bool> visited(V + 1, false);
    visited[startNode] = true;

    while (!s.empty()) {
        auto t = s.top();
        s.pop();

        int node = t.first;
        int dist = t.second;

        if (maxDist < dist) {
            maxDist = dist;
            farthestNode = node;
        }
        
        for (auto& dest : tree[node]) {
            int newNode = dest.first;
            int newDist = dest.second;
            
            if (!visited[newNode]) {
                visited[newNode] = true;
                s.push({newNode, dist + newDist});
            }
                
        }
    }
    return {farthestNode, maxDist};
}


int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> V;

    tree = vector<vector<pair<int, int>>>(V + 1);

    for (int i = 1; i <= V; i++)
    {
        vector<int> tmp;

        int num;
        while ((cin >> num) && (num != -1)) 
            tmp.push_back(num);

        for (int j = 1; j < tmp.size(); j += 2)
            tree[tmp[0]].push_back({tmp[j], tmp[j + 1]});
    }

    auto t = dfs(1);
    auto result = dfs(t.first);

    cout << result.second << endl;

    return 0;
}