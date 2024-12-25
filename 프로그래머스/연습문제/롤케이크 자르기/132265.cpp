#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    // 남아 있는 각 토핑의 개수
    unordered_map<int, int> topping_cnt;
    // 절반에 속한 토핑의 종류
    unordered_set<int> half_topping;

    // 카운터에 각 토핑의 개수 저장
    for(auto top : topping)
        if(topping_cnt.find(top) == topping_cnt.end())
            topping_cnt[top] = 1;
        else
            topping_cnt[top]++;

    // 앞에서부터 토핑을 순회
    for(int i = 0; i < topping.size(); i++) {
        // 절반에 속하는 토핑에 추가하고, 남은 토핑 개수에서 제외
        half_topping.insert(topping[i]);
        topping_cnt[topping[i]]--;
        // 현재 토핑이 없으면 남은 토핑 목록에서 삭제
        if(topping_cnt[topping[i]] == 0)
            topping_cnt.erase(topping[i]);
        // 공평하면 카운팅 증가
        if(topping_cnt.size() == half_topping.size())
            answer++;
    }

    return answer;
}