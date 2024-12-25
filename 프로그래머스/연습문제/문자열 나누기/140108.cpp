#include <string>
#include <vector>

using namespace std;

int solution(string s) {
    int answer = 0;

    vector<string> v;
    int cnt1 = 0, cnt2 = 0; // 첫 글자 카운트, 그 외 카운트

    string str = "";
    char c = 'A'; // 첫 문자

    for (int i = 0; i < s.length(); i++) {
        str += s[i];
        
        if(c == 'A')
            c = s[i];

        if(c == s[i])
            cnt1++;
        else
            cnt2++;

        if(cnt1 == cnt2 && (cnt1 > 0 && cnt2 > 0)) {
            v.push_back(str);
            cnt1 = 0, cnt2 = 0, str = "";
            c = 'A';
        }
    }

    if(c != 'A')
        v.push_back(str);

    answer = v.size();

    return answer;
}