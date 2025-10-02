#include <iostream>
#include <vector>
#include <string>

using namespace std;

int N, M;
vector<int> result;

void dfs(int start, int length)
{
    if (length == M)
    {
        for (int i = 0; i < M; i++)
            cout << result[i] << " ";
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++)
    {
        result.push_back(i);
        dfs(i + 1, length + 1);
        result.pop_back();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    dfs(1, 0);

    return 0;
}