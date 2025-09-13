#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int N, M;
vector<vector<int>> paper;
int total_cheese_cnt = 0;

const int dx[] = {0, 0, -1, 1};
const int dy[] = {-1, 1, 0, 0};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N >> M;

    // 초기 치즈 세팅
    paper.assign(N, vector<int>(M, 0)); 
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> paper[i][j];
            if (paper[i][j] == 1) {
                // 전체 치즈 개수 구하기
                total_cheese_cnt++;
            }
        }
    }

    int hour = 0;
    while (total_cheese_cnt > 0) {
        //
        hour++;

        vector<vector<bool>> visited(N, vector<bool>(M, false));
        queue<pair<int, int>> q;

        q.push({0, 0});
        visited[0][0] = true;
        paper[0][0] = -1; // -1을 외부 공기로 표시

        while (!q.empty()) {
            int y = q.front().first;
            int x = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++) {
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny >= 0 && ny < N && nx >= 0 && nx < M && !visited[ny][nx] && paper[ny][nx] != 1) {
                    visited[ny][nx] = true;
                    paper[ny][nx] = -1; // 외부 공기로 표시
                    q.push({ny, nx});
                }
            }
        }

        vector<pair<int, int>> melting_cheese; // 녹을 치즈를 저장할 리스트

        for (int i = 0; i < N; i++) {
            for (int j = 0; j < M; j++) {
                if (paper[i][j] == 1) {
                    int air_contact_cnt = 0;
                    for (int k = 0; k < 4; k++) {
                        int ny = i + dy[k];
                        int nx = j + dx[k];
                        // 주변이 외부 공기(-1)인지 확인
                        if (paper[ny][nx] == -1)
                            air_contact_cnt++;
                    }

                    if (air_contact_cnt >= 2)
                        melting_cheese.push_back({i, j});
                }
            }
        }
        
        // 치즈들을 녹임
        for (auto& pos : melting_cheese) {
            paper[pos.first][pos.second] = 0;
            total_cheese_cnt--;
        }

        // 외부공기를 다시 0으로 초기화
        for(int i = 0; i < N; ++i)
            for(int j = 0; j < M; ++j)
                if(paper[i][j] == -1)
                    paper[i][j] = 0;
    }

    cout << hour << endl;

    return 0;
}