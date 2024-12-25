#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    
    vector<int> A(board.size(), 0);
    stack<int> S;
    
    for(int move : moves) {
        int column = move - 1;
        int row = A[column];
        
        if(row < board.size()) {
            while(board[row][column] == 0) {
                ++row;
            }
            
            if(S.size() > 0 && S.top() == board[row][column]) {
                answer++;
                S.pop();
            } else {
                S.push(board[row][column]);
            }
            A[column] = ++row;
        }
    }
    answer *= 2;
    return answer;
}