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

    int command = 0;
    int value = 0;
    for (int i = 0; i < N; i++) {
        cin >> command;
        if (command == 1)
            cin >> value;
        
        switch (command) {
            case 1:
                stck.push(value);
                break;
            case 2:
                if (!stck.empty()) {
                    printf("%d\n", stck.top());
                    stck.pop();
                } else {
                    printf("%d\n", -1);
                }
                break;
            case 3:
                printf("%d\n", stck.size());
                break;
            case 4:
                printf("%d\n", stck.empty() ? 1 : 0);
                break;
            case 5:
                printf("%d\n", !stck.empty() ? stck.top() : -1);
                break;
        }
    }

    return 0;
}