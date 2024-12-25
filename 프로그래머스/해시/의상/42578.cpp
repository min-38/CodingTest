#include <string>
#include <vector>
#include <map>

using namespace std;

int solution(vector<vector<string>> clothes) {
    int answer = 0;
    
    map<string, int> m;
    for(int i = 0; i < clothes.size(); i++) {
        string key = clothes[i][1];
        
        auto it = m.find(key);
        if (it == m.end())
            m[key] = 0;
        m[key]++;
    }

    //인덱스기반
    for (auto iter = m.begin() ; iter !=  m.end(); iter++) {
        answer *= iter->second + 1;
    }

    answer += -1;
    return answer;
}