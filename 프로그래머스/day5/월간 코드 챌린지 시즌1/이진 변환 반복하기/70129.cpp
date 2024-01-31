#include <string>
#include <vector>

using namespace std;

vector<int> solution(string s) {
    vector<int> answer(2, 0);
    
    while(s != "1") {
        string s2 = "";
        
        for(char c : s) {
            if(c == '1') s2 += c;
            else answer[1] += 1;
        }
        
        int s2l = s2.length();
        int mok, nmg;
        int idx = 0;
        vector<int> v(s2l, 0);

        do {
            mok = s2l / 2;
            nmg = s2l - mok * 2;
            v[idx++] = nmg;
            s2l = mok;
        } while (mok != 0);

        string s3 = "";
        for (int i = idx - 1; i >= 0; i--) {
            s3 += v[i] + '0';
        }
        
        s = s3;
        answer[0]++;
    }
    return answer;
}