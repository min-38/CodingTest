#include <iostream>
#include <string>
#include <stack>
#include <deque>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    stack<char> left, right;

    string str; // 초기 문자열
    cin >> str;

    for (char c : str)
        left.push(c);

    int M; // 명령 개수
    cin >> M;

    while (M--)
    {
        char command;
        cin >> command;

        char letter;

        if (command == 'P')
        {
            cin >> letter;
            left.push(letter);
        }
        else if (command == 'L')
        {
            if (!left.empty())
            {
                right.push(left.top());
                left.pop();
            }
        }
        else if (command == 'D')
        {
            if (!right.empty())
            {
                left.push(right.top());
                right.pop();
            }
        }
        else if (command == 'B') // 커서 왼쪽에 있는 문자 삭제
        {
            if (!left.empty())
                left.pop();
        }
    }

    deque<char> result;
    // 결과 출력
    while (!left.empty())
    {
        result.push_front(left.top());
        left.pop();
    }

    while (!right.empty())
    {
        result.push_back(right.top());
        right.pop();
    }

    for (char c : result)
        cout << c;
    cout << "\n";
    
    return 0;
}
