#include <string>

using namespace std;

bool solution(string s)
{
    bool answer = true;

    int opened = 0;
    if(s[0] == ')' || s[s.length() - 1] == '(' || s.length() % 2 > 0)
        answer = false;
    else
        for(int i = 0; i < s.length(); i++) {
            if(s[i] == '(')
                opened++;
            else
                if(opened > 0)
                    opened--;
        }

        if(opened != 0)
            answer = false;

    return answer;
}