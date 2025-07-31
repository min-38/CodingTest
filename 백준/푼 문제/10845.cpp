#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    vector<int> v;

    for (int i = 0; i < N; i++)
    {
        string cmd;
        cin >> cmd;

        int value;
        int result;

        if (cmd == "push")
        {
            cin >> value;
            v.push_back(value);
        }
        else if (cmd == "pop")
        {
            result = -1;
            if (v.size() > 0)
            {
                result = v.front();
                v.erase(v.begin());
            }
            cout << result << "\n";
        }
        else if (cmd == "size") cout << v.size() << "\n";
        else if (cmd == "empty") cout << v.empty() << "\n";
        else if (cmd == "front")
        {
            result = -1;
            if (v.size() > 0)
                result = v.front();
            cout << result << "\n";
        }
        else if (cmd == "back")
        {
            result = -1;
            if (v.size() > 0)
                result = v.back();
            cout << result << "\n";
        }
    }

    return 0;
}