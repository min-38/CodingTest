#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    
    vector<int> v(N, 0);
    for (int i = 0; i < N; i++)
        cin >> v[i];

    vector<int> dp(N, 1);
    for (int i = 1; i < N; i++)
        for (int j = 0; j < i; j++)
            if (v[j] < v[i])
                dp[i] = max(dp[i], dp[j] + 1);

    int answer = 0;
    for (int i = 0; i < N; i++)
        answer = max(answer, dp[i]);

    cout << answer << "\n";

    return 0;
}
