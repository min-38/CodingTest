#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;

    priority_queue<int, vector<int>> pq;

    while(N--)
    {
        int x;
        cin >> x;

        if (x == 0)
        {
            if (pq.empty())
            {
                cout << 0 << "\n";
                continue;
            }
            
            cout << pq.top() << "\n";
            pq.pop();
            continue;
        }
        
        pq.push(x);
    }
    return 0;
}