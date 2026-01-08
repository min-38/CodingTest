#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> result(N, 0);
    queue<pair<int, int>> q;
    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        q.push({i, m});
    }

    int second = 0;
    while (!q.empty())
    {
        second++;
        
        auto t = q.front();
        q.pop();
        
        if (--t.second <= 0)
        {
            result[t.first] = second;
            continue;
        }
        q.push(t);
    }

    for (int r : result)
        cout << r << " ";
    cout << "\n";
    
    return 0;
}