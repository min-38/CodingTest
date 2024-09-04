#include <queue>
#include <vector>
using namespace std;

const int MAX_SIZE = 100;
const int dx[4] = {-1, 0, 1, 0};
const int dy[4] = {0, 1, 0, -1};
int check[MAX_SIZE][MAX_SIZE];

// 좌표 정보 및 좌표 연산을 하기 위한 구조체
struct Point {
    int y, x;

    Point(int y, int x) : y(y), x(x) {};

    bool isValid(int width, int height) const {
        return y >= 0 && y < height && x >= 0 && x < width;
    }

    Point move(int i) const { return Point(y + dy[i], x + dx[i]); }

    bool canMoveTo(const vector<vector<int>> &maps) const {
        return maps[y][x] == 1 && check[y][x] == 0;
    }
};

queue<Point> q; // BFS를 위한 큐

int solution(vector<vector<int>> maps) {
    int width = maps[0].size(), height = maps.size();
    q.push({0, 0});
    check[0][0] = 1;

    // 너비 우선 탐색 진행
    while(!q.empty()) {
        Point current = q.front();
        q.pop();
        // 현재 좌표 기준으로 상하좌우를 확인
        for(int i = 0; i < 4; i++) {
            Point next = current.move(i);
            // 범위가 좌표이고 벽이 아닌 경우
            if(next.isValid(width, height) && next.canMoveTo(maps)) {
                check[next.y][next.x] = check[current.y][current.x] + 1;
                q.push({next.y, next.x});
            }
        }
    }

    int destinationX = width - 1, destinationY = height - 1;
    if(check[destinationY][destinationX] == 0)
        return -1; // 도착 지점에 도달할 수 없음

    return check[destinationY][destinationX]; // 도착 지점까지 최단 거리 반환
}