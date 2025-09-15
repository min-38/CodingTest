#include <iostream>
#include <vector>

using namespace std;

int main() {
    
    // 테스트 케이스 입력 받기
    int T;
    cin >> T;

    vector<int> dp(12, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for (int i = 4; i < 12; i++)
        dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];

    while (T--)
    {
        // 정수 n 입력 받기
        int n;
        cin >> n;

        cout << dp[n] << endl;
    }

    return 0;
}