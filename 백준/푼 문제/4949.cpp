#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> stck;
    string s;

    while(true) {
        getline(cin, s);
        if(s[0] == '.')
            break;

        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '[' || s[i] == '(')
                stck.push(s[i]);
            else if (s[i] == ']' || s[i] == ')')
                if (!stck.empty() && (stck.top() + 1 == s[i] || stck.top() + 2 == s[i])) {
                    stck.pop();
                } else {
                    stck.push('c');
                    break;
                }
        }

        printf("%s\n", stck.empty() ? "yes" : "no");
        stack<char> new_stck;
        stck = new_stck;
    }

    return 0;
}