#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> numbers) {
    vector<int> answer;
    
    vector<int> v;
    for(int i = 0; i < numbers.size(); i++)
        for(int j = i + 1; j < numbers.size(); j++)
            v.push_back(numbers[i] + numbers[j]);

    // 선택 정렬
    for(int i = 0; i < v.size(); i++) {
        int l_idx = i; // least index;
        for(int j = i + 1; j < v.size(); j++)
            if(v[l_idx] > v[j])
                l_idx = j;
        
        if(v[l_idx] != v[i]) {
            int tmp = v[l_idx];
            v[l_idx] = v[i];
            v[i] = tmp;
        }
    }

    answer.push_back(v[0]);
    for(int i = 1; i < v.size(); i++)
        if(answer.back() != v[i])
            answer.push_back(v[i]);
    return answer;
}