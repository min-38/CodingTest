#include <string>
#include <vector>

using namespace std;

int solution(int m, int n, vector<vector<int>> puddles) {
    int answer = 0;
    
    vector<vector<int>> block(n + 1, vector<int>(m + 1, 0));
    for (auto &p : puddles) block[p[1]][p[0]] = 1;

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
    if (!block[1][1]) dp[1][1] = 1;

    // 1행
    for (int x = 2; x <= m; ++x)
        dp[1][x] = block[1][x] ? 0 : dp[1][x - 1];

    // 1열
    for (int y = 2; y <= n; ++y)
        dp[y][1] = block[y][1] ? 0 : dp[y - 1][1];

    // 나머지
    for (int y = 2; y <= n; ++y)
        for (int x = 2; x <= m; ++x)
            dp[y][x] = block[y][x] ? 0 : ( (dp[y - 1][x] + dp[y][x - 1]) % 1'000'000'007 );

    answer = dp[n][m];

    return answer;
}
