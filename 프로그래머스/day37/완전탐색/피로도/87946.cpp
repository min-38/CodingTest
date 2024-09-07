#include <string>
#include <vector>

using namespace std;

int maxDepth = 0;
bool visited[8] {
    false,
};

// 던전의 최대 방문수를 갱신하면서 깊이 우선 탐색으로 던전 탐험
void exploreDungeon(int depth, int power, vector<vector<int>> &dungeons) {
    if(maxDepth < depth)
        maxDepth = depth;
    
    for(int i = 0; i < dungeons.size(); i++) {
        // 이미 방문한 던전이거나, 최소 필요 피로도가 현재 남은 피로도보다 많을 때
        if(visited[i] || dungeons[i][0] > power)
            continue;
        
        // 방문이 가능한 모든 경우 확인
        visited[i] = true;
        exploreDungeon(depth + 1, power - dungeons[i][1], dungeons);
        visited[i] = false;
    }
}

int solution(int k, vector<vector<int>> dungeons) {
    // 던전 탐색 시작
    exploreDungeon(0, k, dungeons);

    return maxDepth;
}