#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> enroll, vector<string> referral, vector<string> seller, vector<int> amount) {
    vector<int> answer(enroll.size(), 0);

    vector<int> v(enroll.size(), 0);
    for(int i = 0; i < enroll.size(); i++)
        for(int j = 0; j < enroll.size(); j++) {
            if(referral[i] == "-")
                v[i] = -1;
            else if(referral[i] == enroll[j])
                v[i] = j;
        }

    for(int i = 0; i < seller.size(); i++) {
        int index;
        for(index = 0; index < enroll.size(); index++)
            if(enroll[index] == seller[i])
                break;
        amount[i] *= 100;

        while(index != -1 && amount[i] > 0) {
            answer[index] += amount[i] - (amount[i] * 10 / 100);
            amount[i] = amount[i] * 10 / 100;
            index = v[index];
        }
    }
    return answer;
}