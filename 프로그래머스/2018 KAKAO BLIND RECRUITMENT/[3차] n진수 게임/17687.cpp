#include <string>
#include <vector>

using namespace std;

string solution(int n, int t, int m, int p) {
    string answer = "";
    
    int total_t = t * (t - p);
    
    string a_s = ""; // 전체 문자열
    for(int i = 0; i < total_t; i++)
    {
        string s = ""; // 전체 문자열에 저장할 문자열
        if(i == 0) {
            s = "0";
        } else {
            int num = i;
            
            // 숫자를 n진수로 변환
            while (num > 0) {
                int remainder = num % n;
                s += (remainder < 10) ? (remainder + '0') : (remainder - 10 + 'A');
                num = num / n;
            }   
        }
        
        for (int i = s.length() - 1; i >= 0; i--)
            a_s += s[i];
    }
    
    int location = p - 1;
    for(int i = 0; i < t; i++) {
        answer += a_s[location];
        location += m;
    }
    
    return answer;
}