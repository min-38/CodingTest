#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n;
    cin >> n;
    long long answer = 0;

    for (int i = 1; i <= n; i++)
        answer += (n / i) * i;

    cout << answer << '\n';

    return 0;
}