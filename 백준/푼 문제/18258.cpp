#include <iostream>
#include <string>
#include <queue>
#include <cctype>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    cin.ignore();

    queue<int> q;

    string s;
    for (int i = 0; i < N; i++) {
        getline(cin, s);
        
        if (s == "pop") {
            int pop = -1;
            if(!q.empty()) {
                pop = q.front();
                q.pop();
            }
            printf("%d\n", pop);
        } else if (s == "size")
            printf("%d\n", q.size());
        else if (s == "empty")
            printf("%d\n", q.empty() ? 1 : 0);
        else if (s == "front")
            printf("%d\n", !q.empty() ? q.front() : -1);
        else if (s == "back")
            printf("%d\n", !q.empty() ? q.back() : -1);
        else {
            string num = "";
            for(int j = 5; j < s.length(); j++)
                num += s[j];
            q.push(stoi(num));
        }
    }

    return 0;
}