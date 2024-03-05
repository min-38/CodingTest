#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(string s) {
    int answer = -1;
    
    int x = 0;
    int len = s.length(); // 문자열의 길이
    string tmp = s;
    stack<char> st;
    for(int i = 0; i < len; i++) {
        while(!st.empty()) st.pop(); // 시작 전 stack 비우기

        for(char c : tmp) {
            char top;
            if(st.size() > 0) {
                top = st.top();
                if((top == '(' && c == ')')
                    || (top == '{' && c == '}')
                    || (top == '[' && c == ']')) {
                    st.pop();
                    continue;
                }
            }
            st.push(c);
        }
        if(st.empty()) {
            x++;
        }
        
        // 문자열 왼쪽으로 밀기
        char move = tmp[0];
        for(int j = 1; j < len; j++) {
            tmp[j - 1] = tmp[j];
        }
        tmp[len - 1] = move;
    }
    
    answer = x;
    return answer;
}