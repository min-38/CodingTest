#include <iostream>
#include <vector>

using namespace std;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M;
    cin >> N >> M;

    bool v[101][101] = { false };

    for (int i = 0; i < M; i++)
    {
        int b, s;
        cin >> b >> s;
        v[b][s] = true;
    }

    for (int k = 1; k <= N; k++)
        for (int i = 1; i <= N; i++)
            for (int j = 1; j <= N; j++)
                if (v[i][k] && v[k][j])
                    v[i][j] = true;

    for (int i = 1; i <= N; i++)
    {
        int cnt = 0;
        for (int j = 1; j <= N; j++)
        {
            if (j == i) continue;
            if (v[i][j] == false && v[j][i] == false) cnt++;
        }

        cout << cnt << "\n";
    }

    return 0;
}
