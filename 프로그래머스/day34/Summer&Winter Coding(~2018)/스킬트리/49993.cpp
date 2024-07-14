#include <string>
#include <vector>

using namespace std;


int solution(string skill, vector<string> skill_trees) {
    int answer = 0;
    
    for(string s : skill_trees) {
        string s2 = "";

        for(int i = 0; i < s.length(); i++)
            for(int j = 0; j < skill.length(); j++)
                if(s[i] == skill[j]) {
                    s2 += s[i];
                    break;
                }
        
        bool matched = true;
        for(int i = 0; i < s2.length(); i++)
            if(skill[i] != s2[i]) {
                matched = false;
                break;
            }

        if(matched)
            answer++;
    }
    return answer;
}
// Summer&Winter Coding(~2018)