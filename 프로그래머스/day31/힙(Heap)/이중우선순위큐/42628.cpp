#include <string>
#include <vector>
#include <deque>
using namespace std;

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> dq;
    for(string s : operations) {
        vector<string> op(2, "");
        int idx = 0;
        for(char c : s) {
            if(c == ' ') {
                idx = 1;
                continue;
            }
            op[idx] += c;
        }

        int value = stoi(op[1]);
        if(op[0] == "I") {
            if(dq.size() > 0) {
                if(value > dq.back()) {
                    dq.push_back(value);
                } else if(value < dq.front()) {
                    dq.push_front(value);
                } else {
                    vector<int> tmp;
                    while(value < dq.back()) {
                        tmp.push_back(dq.back());
                        dq.pop_back();
                    }
                    dq.push_back(value);

                    for(int i = tmp.size() - 1; i >= 0; i--)
                        dq.push_back(tmp[i]);
                }
            } else {
                dq.push_back(value);
            }
        } else {
            if(dq.size() == 0)
                continue;
            
            if(value > 0)
                dq.pop_back();
            else
                dq.pop_front();
        }
    }

    if(dq.size() == 0) {
        answer.push_back(0);
        answer.push_back(0);
    } else {
        answer.push_back(dq.back());
        answer.push_back(dq.front());
    }

    return answer;
}