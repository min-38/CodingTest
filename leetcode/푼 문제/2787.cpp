class Solution {
public:
    static constexpr int MOD = 1'000'000'007;

    int numberOfWays(int n, int x) {
        vector<int> v;
        int start = 1;

        while (true)
        {
            int num = pow(start, x);
            if (num > n)
                break;
            start++;
            v.push_back(num);
        }

        vector<int> dp(n + 1, 0);
        dp[0] = 1;

        for (int p : v)
        {
            for (int s = n; s >= p; --s)
            {
                dp[s] += dp[s - p];
                if (dp[s] >= MOD)
                    dp[s] -= MOD;
            }
        }

        return dp[n];
    }
};