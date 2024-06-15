#include <string>
#include <vector>

using namespace std;

typedef vector<vector<int>> towers;

void connected(int start, towers& t, vector<bool>& visited) {
    visited[start] = true;
    
    for(int i = 0; i < t[start].size(); i++) {
        if(visited[t[start][i]]) continue;
        connected(t[start][i], t, visited);
    }
}

int solution(int n, vector<vector<int>> wires) {
    int answer = -1;
    
    towers t(n + 1); // 타워
    vector<bool> visited(n + 1, false); // 방문한 노드
    int index = 0, tmp;
    
    while(index < n) {
        tmp = 0;
        
        for(int i = 1; i <= n; i++) {
            t[i].clear();
            visited[i] = false;
        }

        for(int i = 0; i < n - 1; i++)
            if(index != i) {
                t[wires[i][0]].push_back(wires[i][1]);
                t[wires[i][1]].push_back(wires[i][0]);
            }
        
        connected(1, t, visited);
        
        for(int i = 1; i <= n; i++)
            if(visited[i])
                tmp++;
        
        tmp = n - tmp * 2;
        if(tmp < 0) tmp *= -1;

        if(answer < 0 || answer > tmp)
            answer = tmp;
        
        index++;
    }
    
    return answer;
}