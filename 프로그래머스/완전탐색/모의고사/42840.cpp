#include <algorithm>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    
    vector<int> a_ans = {1, 2, 3, 4, 5};
    vector<int> b_ans = {2, 1, 2, 3, 2, 4, 2, 5};
    vector<int> c_ans = {3, 3, 1, 1, 2, 2, 4, 4, 5, 5};
    
    vector<int> correct(3);
    for(int i = 0; i < answers.size(); i++) {
        if(answers[i] == a_ans[i % a_ans.size()])
            correct[0]++;
        if(answers[i] == b_ans[i % b_ans.size()])
            correct[1]++;
        if(answers[i] == c_ans[i % c_ans.size()])
            correct[2]++;
    }
    
    int max = *max_element(correct.begin(), correct.end());
    for(int i = 0; i < 3; i++)
        if(correct[i] == max)
            answer.push_back(correct[i]);

    return answer;
}