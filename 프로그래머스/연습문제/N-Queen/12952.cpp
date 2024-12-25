#include <algorithm>
#include <vector>

using namespace std;

// 현재 행에 이미 다른 퀸이 있는지 확인
bool isSameRow(int placedRow, int currentRow) { return placedRow == currentRow; }

// 대각선에 다른 퀸이 있는지 확인
bool isDiagonalAttack(int placedCol, int placedRow, int currentCol, int currentRow) {
    return abs(placedCol - currentCol) == abs(placedRow - currentRow);
}

// 퀸을 안전하게 배치할 수 있는지 확인
bool isSafePosition(const vector<int> &queen, int col, int row) {
    for(int i = 0; i < col; i++)
        if(isSameRow(queen[i], row) || isDiagonalAttack(i, queen[i], col, row))
            return false;
}

// 퀸을 배치하는 함수
long long placeQueens(vector<int> &queen, int col) {
    int n = queen.size();
    if(col == n)
        return 1;
    
    long long count = 0;
    for(int row = 0; row < n; row++) {
        // 퀸을 놓을 수 있는 위치면 퀸을 배치
        if(isSafePosition(queen, col, row)) {
            queen[col] = row;
            count += placeQueens(queen, col + 1);
            queen[col] = -1;
        }
    }
    return count;
}

int solution(int n) {
    vector<int> queen(n, -1);

    return placeQueens(queen, 0); // 퀸을 놓을 수 있는 경우의 수를 반환
}