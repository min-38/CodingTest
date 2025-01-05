#include <string>
#include <vector>

using namespace std;

vector<bool> visited;

void bfs(const vector<vector<int>> &computers, int start) {
    visited[start] = true;

    for(int i = 0; i < computers[start].size(); i++)
        if(i != start && !visited[i] && computers[start][i] == 1)
            bfs(computers, i);
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;

    visited = vector<bool>(n, false);

    for(int i = 0; i < n; i++)
        if(!visited[i]) {
            bfs(computers, i);
            answer++;
        }
    return answer;
}