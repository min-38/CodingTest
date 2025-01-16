#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<vector<int>> skill) {
    int answer = 0;

    int N = board.size();
    int M = board[0].size();

    vector<vector<int>> board2(N + 1, vector<int>(M + 1, 0));

    int type, r1, c1, r2, c2, degree;
    for (auto v : skill) {
        type = v[0];
        r1 = v[1], c1 = v[2];
        r2 = v[3], c2 = v[4];
        degree = (type == 2) ? v[5] : v[5] * -1;

        board2[r1][c1] += degree;
        board2[r1][c2 + 1] -= degree;
        board2[r2 + 1][c1] -= degree;
        board2[r2 + 1][c2 + 1] += degree;
    }

    // 세로
    for(int i = 0; i < M + 1; i++)
        for(int j = 0; j < N; j++)
            board2[j + 1][i] += board2[j][i];
        
    // 가로
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M + 1; j++)
            board2[i][j + 1] += board2[i][j];

    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++) {
            board[i][j] += board2[i][j];
            if (board[i][j] > 0)
                answer++;
        }

    return answer;
}
