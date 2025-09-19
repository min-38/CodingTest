#include <iostream>
#include <vector>
#include <climits>

using namespace std;

int main()
{
    int N;
    cin >> N;

    // 칠하는 비용 세팅
    vector<vector<int>> costs(N, vector<int>(3, 0));
    for (int i = 0; i < N; i++)
        for (int j = 0; j < 3; j++)
            cin >> costs[i][j];

    vector<vector<int>> dp(N, vector<int>(3, 0));
    dp[0][0] = costs[0][0];
    dp[0][1] = costs[0][1];
    dp[0][2] = costs[0][2];

    dp[1][0] = costs[1][0] + min(dp[0][1], dp[0][2]);
    dp[1][1] = costs[1][1] + min(dp[0][0], dp[0][2]);
    dp[1][2] = costs[1][2] + min(dp[0][0], dp[0][1]);
    
    for (int i = 2; i < N; i++)
    {
        dp[i][0] = costs[i][0] + min(dp[i - 1][1], dp[i - 1][2]);
        dp[i][1] = costs[i][1] + min(dp[i - 1][0], dp[i - 1][2]);
        dp[i][2] = costs[i][2] + min(dp[i - 1][0], dp[i - 1][1]);
    }

    int result = INT_MAX;
    for (int i = 0; i < 3; i++)
        if (result > dp[N - 1][i])
            result = dp[N - 1][i];

    cout << result << endl;

    return 0;
}