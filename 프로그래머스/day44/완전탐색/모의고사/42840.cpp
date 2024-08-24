#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> a_ans = {1, 2, 3, 4, 5};
    vector<int> b_ans = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c_ans = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    int correct[3] = {0, 0, 0};
    int idx = 0;
    for(int num : answers) {
        if(a_ans[idx >= a_ans.size() ? idx % a_ans.size() : idx] == num)
            correct[0]++;
        if(b_ans[idx >= b_ans.size() ? idx % b_ans.size() : idx] == num)
            correct[1]++;
        if(c_ans[idx >= c_ans.size() ? idx % c_ans.size() : idx] == num)
            correct[2]++;
        ++idx;
    }
    
    int max = 0;
    for(int i = 0; i < 3; i++)
        if(max < correct[i]) {
            answer.clear();
            answer.push_back(i + 1);
            max = correct[i];
        } else if(max == correct[i]) {
            answer.push_back(i + 1);
        }

    return answer;
}