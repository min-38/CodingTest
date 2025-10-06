#include <iostream>
#include <vector>

using namespace std;

int N;
vector<int> v;
vector<int> operators(4); // +, -, *, /

int maxValue = -1e9;
int minValue = 1e9;

void dfs(int idx, int result)
{
    int value = v[idx];

    if (idx == N)
    {
        if (result > maxValue)
            maxValue = result;
        if (result < minValue)
            minValue = result;
        return;
    }

    for (int i = 0; i < 4; i++)
    {
        if (operators[i] > 0)
        {
            operators[i]--;
            if (i == 0)
                dfs(idx + 1, result + value);
            else if (i == 1)
                dfs(idx + 1, result - value);
            else if (i == 2)
                dfs(idx + 1, result * value);
            else if (i == 3)
                dfs(idx + 1, result / value);
            operators[i]++;
        }
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N;

    v.assign(N, 0);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    for (int i = 0; i < 4; i++)
        cin >> operators[i];

    dfs(1, v[0]);

    cout << maxValue << "\n" << minValue << "\n";

    return 0;
}