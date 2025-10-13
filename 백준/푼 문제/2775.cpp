#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int T; //  테스트케이스 수
    cin >> T;

    while (T--)
    {
        int k, n;
        cin >> k >> n;

        vector<vector<int>> v(k + 1, vector<int>(n + 1, 0));

        for (int i = 1; i <= n; i++)
            v[0][i] = i;

        for (int i = 1; i<= k; i++)
            for (int j = 1; j <= n; j++)
                v[i][j] = v[i - 1][j] + v[i][j - 1];

        cout << v[k][n] << endl;
    }
    return 0;
}