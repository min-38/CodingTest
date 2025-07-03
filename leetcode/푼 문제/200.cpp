class Solution {
public:
    int numIslands(std::vector<std::vector<char>>& grid) {
        // 변수
        int result = 0;
        int rows = grid.size();         // 행
        int cols = grid[0].size();      // 열
        vector<bool> visited(rows * cols, false);
        int dx[] = {-1, 1, 0, 0}; // row 변화량
        int dy[] = {0, 0, -1, 1}; // col 변화량

        // 로직
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < cols; j++) {

                if (grid[i][j] == '1' && !visited[i * cols + j]) {
                    result++; // 섬 개수 증가
                    
                    queue<pair<int, int>> q;
                    q.push(make_pair(i, j));

                    // 방문
                    visited[i * cols + j] = true;

                    while (!q.empty()) { 
                        pair<int, int> p = q.front();
                        q.pop();

                        int x = p.first;  // 현재 행
                        int y = p.second; // 현재 열

                        for (int i = 0; i < 4; ++i) {
                            int nx = x + dx[i]; // 다음 행
                            int ny = y + dy[i]; // 다음 열

                            if (nx >= 0 && nx < rows &&
                                ny >= 0 && ny < cols &&
                                grid[nx][ny] == '1' && !visited[nx * cols + ny])
                            {
                                visited[nx * cols + ny] = true;
                                q.push(make_pair(nx, ny));
                            }
                        }
                    }
                }
            }
        }
        return result;
    }
};