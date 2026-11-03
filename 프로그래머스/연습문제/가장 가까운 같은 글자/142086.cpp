#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer;
    vector<int> last(26, -1);

    for (int i = 0; i < s.length(); i++) {
        int idx = s[i] - 'a';
        answer.push_back(last[idx] == -1 ? -1 : i - last[idx]);
        last[idx] = i;
    }

    return answer;
}
