#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int solution(vector<int> topping) {
    int answer = 0;

    unordered_map<int, int> um;
    for(int i = 0; i < topping.size(); i++)
        um[topping[i]]++;

    int sister = um.size();

    unordered_set<int> mine;
    int idx = 0;
    while(mine.size() <= sister) {
        mine.insert(topping[idx]);
        um[topping[idx]]--;
        if(um[topping[idx]] == 0)
            sister--;

        if(mine.size() == sister)
            answer++;
        idx++;
    }

    return answer;
}