#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
    vector<string> answer;
    
    vector<vector<string>> v(26);
    
    for (string s : strings)
    {
        int idx = s[n] - 97;
        v[idx].push_back(s);
    }
    
    for (vector<string>& sv : v)
    {
        sort(sv.begin(), sv.end());
        for (string s : sv)
            answer.push_back(s);
    }

    return answer;
}
