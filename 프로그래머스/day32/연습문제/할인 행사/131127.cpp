#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<string> want, vector<int> number, vector<string> discount) {
    int answer = 0;
    unordered_map<string, int> wantMap; // want를 키, number를 값으로 wantMap 선언

    for(int i = 0; i < want.size(); i++)
        wantMap[want[i]] = number[i];
    
    for(int i = 0; i < discount.size() - 9; i++) {
        // i일 회원가입 시 할인받을 수 있는 품목을 키, 개수를 값으로 discound_10d 선언
        unordered_map<string, int> discount_10d;

        // 각 할인 품목을 키로 개수 저장
        for(int j = i; j < 10 + i; j++)
            discount_10d[discount[j]]++;

        // 할인 상품의 품목 및 개수가 원하는 상품의 품목 및 개수와 일치하면 카운트 증가
        if(wantMap == discount_10d) answer++;
    }

    return answer;
}