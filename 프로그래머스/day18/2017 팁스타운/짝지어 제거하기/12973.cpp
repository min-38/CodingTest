#include <string>
#include <stack>
using namespace std;

int solution(string s)
{
    int answer = 0;
    
    stack<char> st;
    for(char c : s) {
        if(st.size() > 0) {
            if(st.top() == c) {
                st.pop();
                continue;
            }
        }
        st.push(c);
    }

    if(st.size() == 0) {
        answer = 1;
    }
    
    return answer;
}