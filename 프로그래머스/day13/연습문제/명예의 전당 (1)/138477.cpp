#include <string>
#include <vector>
#include <deque>

using namespace std;

vector<int> solution(int k, vector<int> score) {
    vector<int> answer;

    deque<int> dq;

    for(int i = 0; i < score.size(); i++) {
        int idx = 0;
        for(idx; idx < dq.size(); idx++) {
            if(dq[idx] < score[i]) {
                break;
            }
        }

        if(idx == 0) {
            dq.push_front(score[i]);
        } else {
            vector<int> tmp;
            for(int j = dq.size(); j > idx; j--) {
                tmp.push_back(dq.back());
                dq.pop_back();
            }
            dq.push_back(score[i]);
            for(int j = tmp.size(); j > 0; j--) {
                dq.push_back(tmp[j - 1]);
            }
        }

        if(dq.size() > k) {
            dq.pop_back();
        }
        answer.push_back(dq.back());
    }
    return answer;
}