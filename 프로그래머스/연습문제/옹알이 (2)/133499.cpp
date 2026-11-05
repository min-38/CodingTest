#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    string babble[4] = {"aya", "ye", "woo", "ma"};

    for (const string& s : babbling) {
        string str = "";
        string prev = "";
        bool fail = false;

        for (char c : s) {
            str += c;

            for (const string& b : babble) {
                if (str == b) {
                    if (str == prev) fail = true;  // 연속 발음
                    prev = str;
                    str = "";
                    break;
                }
            }

            if (fail || str.length() > 3) {
                fail = true;
                break;
            }
        }

        if (!fail && str.empty())
            answer++;
    }

    return answer;
}
