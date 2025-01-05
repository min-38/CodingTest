#include <iostream>
#include <stack>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    stack<int> stck;

    int student;
    int target = 1;
    for(int i = 0; i < N; i++) {
        cin >> student;

        stck.push(student);
        
        while(!stck.empty() && target == stck.top()) {
            target++;
            stck.pop();
        }
    }

    if(stck.empty())
        printf("Nice\n");
    else
        printf("Sad\n");

    return 0;
}