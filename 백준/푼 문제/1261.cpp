#include <iostream>
#include <vector>
#include <string>
#include <deque>
#include <limits>

struct State {
    int y, x; // 좌표
};

// 상하좌우
const int dy[] = {-1, 1, 0, 0};
const int dx[] = {0, 0, -1, 1};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);

    int M, N; // M: 가로, N: 세로
    std::cin >> M >> N;

    std::vector<std::vector<int>> maze(N, std::vector<int>(M));
    for (int i = 0; i < N; ++i) {
        std::string row;
        std::cin >> row;
        for (int j = 0; j < M; ++j) {
            maze[i][j] = row[j] - '0';
        }
    }

    const int INF = std::numeric_limits<int>::max();
    std::vector<std::vector<int>> min_crashed(N, std::vector<int>(M, INF));
    
    // 0-1 BFS를 위해 deque 사용
    std::deque<State> dq;

    // 시작점 초기화
    min_crashed[0][0] = 0;
    dq.push_front({0, 0});

    while (!dq.empty()) {
        State current = dq.front();
        dq.pop_front();

        // 이미 더 좋은 경로가 있다면 건너뜀
        if (maze[current.y][current.x] > min_crashed[current.y][current.x]) {
            continue;
        }

        // 상하좌우 탐색
        for (int i = 0; i < 4; ++i) {
            int nextY = current.y + dy[i];
            int nextX = current.x + dx[i];

            // 맵 경계 체크
            if (nextY >= 0 && nextY < N && nextX >= 0 && nextX < M) {
                int cost = maze[nextY][nextX];
                
                // 새로운 경로가 기존 경로보다 벽을 덜 부순다면
                if (min_crashed[nextY][nextX] > min_crashed[current.y][current.x] + cost) {
                    min_crashed[nextY][nextX] = min_crashed[current.y][current.x] + cost;
                    
                    // 비용이 0이면 앞에, 1이면 뒤에 둬서 0인 길 먼저 탐색
                    if (cost == 0)
                        dq.push_front({nextY, nextX});
                    else
                        dq.push_back({nextY, nextX});
                }
            }
        }
    }

    // 최종 결과 출력
    std::cout << min_crashed[N - 1][M - 1] << std::endl;

    return 0;
}