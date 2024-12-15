#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

string solution(string X, string Y) {
    string answer = "";

    vector<int> v;
    map<int, int> mx, my;

    for (char c : X)
        mx[c - '0']++;
    for (char c : Y)
        my[c - '0']++;

    for (int i = 0; i < 10; i++)
        if(mx[i] > 0 && my[i] > 0) {
            int cnt = mx[i];
            if(mx[i] > my[i])
                cnt = my[i];

            for (int j = 0; j < cnt; j++)
                v.push_back(i);
        }
    
    if(v.size() == 0)
        return "-1";

    sort(v.rbegin(), v.rend());
    
    if(v[0] == 0)
        return "0";
    
    for (int i : v)
        answer += i + '0';

    return answer;
}