#include <string>
#include <vector>
#include <map>

using namespace std;


string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
    
    multimap<string, bool> m;
    for(int i = 0; i < participant.size(); i++)
        m.insert(make_pair(participant[i], false));
    
    for(int i = 0; i < completion.size(); i++) {
        auto range = m.equal_range(completion[i]);
        for (auto it = range.first; it != range.second; ++it)
            if (it->first == completion[i]) {
                m.erase(it);
                break;
            }
    }

    for(const auto& pair : m)
        if(!pair.second) {
            answer = pair.first;
            break;
        }
        
    return answer;
}