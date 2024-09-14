#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> keyinput, vector<int> board) {
    // 현재 위치를 나타내는 크기가 2이고 값이 모두 0인 벡터 선언
    vector<int> v(2, 0);

    // 키 입력 순서대로 캐릭터 이동
    for(string s : keyinput) {
        if(s == "up" && v[1] < +board[1] / 2) v[1]++;
        else if(s == "down" && v[1] > -board[1] / 2) v[1]--;
        else if(s == "left" && v[0] > -board[0] / 2) v[0]--;
        else if(s == "right" && v[0] < +board[0] / 2) v[0]++;
    }

    return v;
}