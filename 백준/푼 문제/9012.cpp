#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    string s;
    for (int i = 0; i < N; i++) {
        stack<char> stck;
        cin >> s;

        for (int j = 0; j < s.length(); j++) {
            if(stck.size() > s.length() - j)
                break;

            if(!stck.empty() && stck.top() == '(' && s[j] == ')') {
                stck.pop();
                continue;
            }
            stck.push(s[j]);
        }
        printf("%s\n", stck.empty() ? "YES" : "NO");
    }

    return 0;
}