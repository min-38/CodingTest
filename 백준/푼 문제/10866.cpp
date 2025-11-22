#include <iostream>
#include <deque>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    deque<int> dq;

    while(N--)
    {
        string command;
        int num;

        cin >> command;
        if (command == "push_front" || command == "push_back")
            cin >> num;
        
        if (command == "push_front")
        {
            dq.push_front(num);
        }
        else if (command == "push_back")
        {
            dq.push_back(num);
        }
        else if (command == "pop_front")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        }
        else if (command == "pop_back")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
            {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        }
        else if (command == "size")
        {
            cout << dq.size() << "\n";
        }
        else if (command == "empty")
        {
            cout << (dq.empty() ? 1 : 0) << "\n";
        }
        else if (command == "front")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.front() << "\n";
        }
        else if (command == "back")
        {
            if (dq.empty())
                cout << -1 << "\n";
            else
                cout << dq.back() << "\n";
        }
    }
    return 0;
}