#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    
    unordered_map<string, int> um;
    for(int i = 0; i < genres.size(); i++)
        um[genres[i]] += plays[i];
    
    vector<pair<string, int>> vec(um.begin(), um.end());
    sort(vec.begin(), vec.end(), [](const auto &a, const auto &b) {
            return a.second > b.second;
    });

    for (const auto &pair : vec) {
        int limit = 0;
        while(limit++ < 2) {
            int max_idx = -1;
            for(int i = 0; i < plays.size(); i++)
                if(pair.first == genres[i] && (max_idx < 0 && plays[i] != -1 || plays[max_idx] < plays[i]))
                    max_idx = i;
            if(max_idx == -1)
                break;
            answer.push_back(max_idx);
            plays[max_idx] = -1;
        }
    }
    return answer;
}