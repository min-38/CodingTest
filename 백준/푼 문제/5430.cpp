#include <iostream>
#include <string>
#include <deque>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int T; // Testcases
    cin >> T;
    
    while (T--)
    {
        string p;
        cin >> p;

        int n;
        cin >> n;

        string arr;
        cin >> arr;

        // arr parsing
        deque<int> dq;
        string num = "";
        for (char c : arr)
        {
            if (isdigit(c)) {
                num += c;
            } else {
                if (!num.empty()) {
                    dq.push_back(stoi(num));
                    num = "";
                }
            }
        }

        bool reversed = false; // 처음에는 앞에서 처리, true면 뒤에서 처리
        bool error = false;

        for (char c : p)
        {
            if (c == 'R')
            {
                reversed = !reversed;
                continue;
            }
                
            if (c == 'D')
            {
                if (dq.empty())
                {
                    error = true;
                    break;
                }

                if (!reversed)
                    dq.pop_front();
                else
                    dq.pop_back();
            }
        }

        if (error)
        {
            cout << "error\n";
            continue;
        }
        else
        {
            cout << "[";
            if (reversed)
            {
                for (auto it = dq.rbegin(); it != dq.rend(); ++it)
                {
                    cout << *it;
                    if (it + 1 != dq.rend())
                        cout << ",";
                }
            }
            else
            {
                for (auto it = dq.begin(); it != dq.end(); ++it)
                {
                    cout << *it;
                    if (it + 1 != dq.end())
                        cout << ",";
                }
            }
            cout << "]\n";
        }
    }

    return 0;
}