#include <string>
#include <cctype>

using namespace std;

string solution(string s) {
    string answer = s;
    
    int start = 0;
    for(int i = 0; i <= answer.length(); i++) {
        if(s[i] == ' ' || i == answer.length()) {
            if(!isdigit(answer[start]) && islower(answer[start])) {
                answer[start] -= 32;
            }
            start = i + 1;
        } else {
            if(!isdigit(answer[i]) && isupper(answer[i])) answer[i] += 32;
        }
    }
    return answer;
}