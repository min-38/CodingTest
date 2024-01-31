#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, vector<string> words) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(0);

    int turn = 1;
    int idx = 0;
    bool fail = false; // 탈락 여부
    while(idx < words.size()) {
        for(int i = 1; i <= n; i++) {
            string word = words[idx];
            if(idx > 0) {
                string rword = words[idx - 1]; // recent word

                if(word[0] != rword[rword.length() - 1]) {
                    fail = true;
                }

                for(int j = 0; j < idx; j++) {
                    if(words[j] == word) {
                        fail = true;
                        break;
                    }
                }
            }

            if(fail) {
                answer[0] = i;
                answer[1] = turn;
                break;
            }
            idx++;
        }

        if(fail) break;
        turn++;
    }

    return answer;
}