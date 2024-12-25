#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantMap; // want를 키, number를 값으로 wantMap 선언

    for(int i = 0; i < want.size(); i++)
        wantMap[want[i]] = number[i];
    
    unordered_map<string, int> discount_set;
    // 9일치 정보를 미리 할당
    for(int i = 0; i < 9; i++)
        discount_set[discount[i]]++;

    // discount_set에 최근의 정보를 추가하고, 가장 오래된 정보를 제공하는 식으로 진행
    // 비교할 때엔 항상 10일의 정보를 가지고 있다.    
    for(int i = 9; i < discount.size(); i++) {
        discount_set[discount[i]]++;
        // discount_set은 discount[i - 9..i]의 정보를 가지고 있음.
        if(wantMap == discount_set) answer++;
        if(--discount_set[discount[i - 9]] == 0)
            discount_set.erase(discount[i - 9]);
    }
    return answer;
}