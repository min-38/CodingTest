#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> triangle) {
    int answer = 0;
    
    int n = triangle.size();
    int m;
    vector<vector<int>> dp(n);
    dp[0].push_back(triangle[0][0]);
    
    for (int i = 0; i < n - 1; i++) {
        m = triangle[i + 1].size();
        dp[i + 1].resize(m, 0);

        for (int j = 0; j < m - 1; j++) {
            dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + triangle[i + 1][j]);
            dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + triangle[i + 1][j + 1]);
        }
    }

    answer = *max_element(dp[n - 1].begin(), dp[n - 1].end());
    return answer;
}