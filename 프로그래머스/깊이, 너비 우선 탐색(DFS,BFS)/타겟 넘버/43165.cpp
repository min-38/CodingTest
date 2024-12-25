#include <string>
#include <vector>

using namespace std;

void calculate(int sum, int idx, const vector<int> numbers, const int& target, int& answer) {
    if(idx == numbers.size()) {
        if(sum == target)
            answer++;
    } else {
        calculate(sum + numbers[idx], idx + 1, numbers, target, answer);
        calculate(sum - numbers[idx], idx + 1, numbers, target, answer);   
    }
}

int solution(vector<int> numbers, int target) {
    int answer = 0;
    
    calculate(0, 0, numbers, target, answer);

    return answer;
}