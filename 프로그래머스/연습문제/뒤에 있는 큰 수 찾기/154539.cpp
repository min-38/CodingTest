#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    answer.resize(numbers.size(), -1);

    vector<int> tmp;
    for(int i = 0; i < numbers.size(); i++) {
        tmp.push_back(numbers[i]);
        for(int j = i - 1; j >= 0; j--) {
            if(tmp[j] == 0) {
                continue;
            } else if(tmp[i] > tmp[j]) {
                answer[j] = tmp[i];
                tmp[j] = 0;
            } else {
                break;
            }
        }
    }
    return answer;
}