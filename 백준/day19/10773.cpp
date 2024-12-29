#include <iostream>
#include <vector>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<int> stck;
    int N;
    cin >> N;

    int answer = 0;
    int value = 0;
    for (int i = 0; i < N; i++) {
        cin >> value;
        if(value == 0) {
            if(!stck.empty()) {
                answer -= stck.top();
                stck.pop();
            }
            continue;
        }
        answer += value;
        stck.push(value);
    }
    printf("%d\n", answer);

    return 0;
}