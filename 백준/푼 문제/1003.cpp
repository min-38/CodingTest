#include <iostream>
#include <vector>

using namespace std;

const int limit = 40;

struct Node {
    int zeroCnt = 0;
    int oneCnt = 0;
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    // 테스트 케이스
    int T;
    cin >> T;

    vector<Node> dp(limit);

    dp[0] = {1, 0};
    dp[1] = {0, 1};

    for (int i = 2; i <= limit; i++)
        dp[i] = {
            dp[i - 1].zeroCnt + dp[i - 2].zeroCnt,
            dp[i - 1].oneCnt + dp[i - 2].oneCnt
        };

    while (T--)
    {
        int n;
        cin >> n;

        cout << dp[n].zeroCnt << " " << dp[n].oneCnt << "\n";
    }

    return 0;
}