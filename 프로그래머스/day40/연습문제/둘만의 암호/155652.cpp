#include <string>
#include <vector>
using namespace std;

char loop(char c) {
    if(c > 122) c = 96 + (122 - c) * -1;
    return c;
}

string solution(string s, string skip, int index) {
    string answer = "";

    for(char c : s) {
        char chgc = c;
        for(int i = 1; i <= index; i++) {
            chgc = loop(chgc + 1);
            for(char sc : skip)
                if(sc == chgc) {
                    i--;
                    break;
                }
        }
        answer += chgc;
    }

    return answer;
}