#include <stack>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> prices) {
    // 가격이 떨어지지 않은 기간을 저장한 벡터
    vector<int> answer(prices.size());
    // 스택에는 prices의 인덱스가 들어감. 이전 가격과 현재 가격을 비교하기 위한 용도로 사용
    stack<int> s;

    int priceNum = prices.size();

    for(int i = 0; i < priceNum; i++) {
        while(!s.empty() && prices[s.top()] > prices[i]) {
            // 가격이 떨어졌으므로 이전 가격의 기간 계산
            answer[s.top()] = i - s.top();
            s.pop();
        }
        s.push(i);
    }
    // 스택에 남아 있는 가격은 가격이 떨어지지 않는 경우
    while(!s.empty()) {
        answer[s.top()] = priceNum - s.top() - 1;
        s.pop();
    }
    return answer;
}