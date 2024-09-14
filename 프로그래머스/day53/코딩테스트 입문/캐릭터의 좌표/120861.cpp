#include <string>
#include <vector>

using namespace std;

int maxX;
int maxY;

bool check(int x, int y) {
    return (x <= maxX && x >= maxX * -1) && (y <= maxY && y >= maxY * -1);
}

vector<int> solution(vector<string> keyinput, vector<int> board) {
    vector<int> answer(2, 0);

    maxX = board[0] / 2;
    maxY = board[1] / 2;

    for(string s : keyinput) {
        int x = answer[0];
        int y = answer[1];
        if(s == "left")
            x -= 1;
        else if(s == "right")
            x += 1;
        else if(s == "down")
            y -= 1;
        else
            y += 1;

        if(check(x, y)) {
            answer[0] = x;
            answer[1] = y;
        }
    }
    return answer;
}