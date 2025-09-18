#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n;
    cin >> n;

    vector<int> stairs(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> stairs[i];

    if (n == 1)
    {
        cout << stairs[1] << endl;
        return 0;
    }

    vector<vector<int>> dp(n + 1, vector<int>(3, 0));
    dp[1][1] = stairs[1];
    
    dp[2][1] = dp[1][1] + stairs[2];
    dp[2][2] = stairs[2];

    for (int i = 3; i <= n; i++)
    {
        dp[i][1] = dp[i - 1][2] + stairs[i];
        dp[i][2] = max(dp[i - 2][1], dp[i - 2][2]) + stairs[i];
    }

    cout << max(dp[n][1], dp[n][2]) << endl;

    return 0;
}