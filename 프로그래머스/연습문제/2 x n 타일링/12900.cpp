#include <string>
#include <vector>

using namespace std;

int solution(int n) {
    int answer = 0;

    vector<int> dp(n + 1);
    dp[0] = 0;
    dp[1] = 1;
    
    for (int i = 2; i <= n; i++) {
        dp[i] = dp[i - 1] + 1;
        if (i < n - 1)
            dp[i] += dp[i - 2] + 1;
        dp[i] = dp[i] % 1000000007;
    }
    
    answer = dp[n];

    return dp[n];
}