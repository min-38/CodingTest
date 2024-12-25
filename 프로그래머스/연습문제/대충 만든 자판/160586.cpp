#include <string>
#include <vector>

using namespace std;

vector<int> answer;

int check_character(char c, vector<string> keymap) {

    int i = 0;
    while (1) {
        int cnt = 0;
        for (int j = 0; j < keymap.size(); j++) {
            if (keymap[j].length() < i) {
                if (++cnt == keymap.size()) return -1;
                continue;
            }

            if (c == keymap[j][i]) return i + 1;
        }
        i++;
    }

    return -1;
}

vector<int> solution(vector<string> keymap, vector<string> targets) {
    answer = vector<int>(targets.size(), 0);

    bool exist; // 찾는 문자가 있으면 True, 없으면 False
    for (int i = 0; i < targets.size(); i++) {
        for (char c : targets[i]) {
            int result = check_character(c, keymap);
            if (result == -1) {
                answer[i] = -1;
                break;
            }
            answer[i] += result;
        }
    }
    return answer;
}