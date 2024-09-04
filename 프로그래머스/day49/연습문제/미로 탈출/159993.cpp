#include <queue>
#include <string>
#include <vector>

using namespace std;

// 현재 좌표, 해당 좌표까지 이동 횟수
struct Point {
    int y, x, cnt;
};

// 샹하좌우로 이동하기 위한 오프셋
int dy[4] = {-1, 0, 1, 0};
int dx[4] = {0, 1, 0, -1};
int n, m;

// 현재 좌표가 유효한 좌표인지 확인
bool isWithinRange(int y, int x) { return 0 <= y && y < n && 0 <= x && x < m; }

// 시작 좌표 확인
Point findStartPoint(char start, vector<string> &maps) {
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            if(maps[i][j] == start) {
                return {i, j, 0};
            }
        }
    }
    return {-1, -1, -1}; // 시작점을 찾지 못한 경우
}

int bfs(char start, char end, vector<string> &maps) {
    bool visited[101][101] = {false}; // 방문 여부를 체크하는 배열
    queue<Point> q;

    q.push(findStartPoint(start, maps)); // 시작 노드부터 너비 우선 탐색하도록 추가

    while(!q.empty()) {
        Point current = q.front();
        q.pop();

        // 목적지에 도달했으면 해당 목적지까지 이동 횟수 반환
        if(maps[current.y][current.x] == end) {
            return current.cnt;
        }
        // 현재 위치 기준 상하좌우 확인
        for(int i = 0; i < 4; i++) {
            int ny = current.y + dy[i];
            int nx = current.x + dx[i];

            if(isWithinRange(ny, nx) && !visited[ny][nx] && maps[ny][nx] != 'X') {
                // 후보 좌표가 미로 범위 내에 있고, 아직 방문하지 않았으면 탐색 대상에 추가
                q.push({ny, nx, current.cnt + 1});
                visited[ny][nx] = true;
            }
        }
    }

    return -1;
}

int solution(vector<string> maps) {
    n = maps.size();
    m = maps[0].size();

    // 시작 지점부터 L까지 최단 거리를 구함
    int distanceToL = bfs('S', 'L', maps);
    if(distanceToL == -1)
        return - 1;
    
    // L부터 도착 지점까지 최단 거리를 구함
    int distanceToE = bfs('L', 'E', maps);
    return distanceToE == -1 ? -1 : distanceToL + distanceToE;
}