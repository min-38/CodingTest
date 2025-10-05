#include <iostream>
#include <vector>

using namespace std;

int answer = 0;
int N;
vector<vector<bool>> v;

bool isSafe(int line, int pos)
{
    for (int i = 1; i < line; i++)
        if (v[i][pos])
            return false;

    for (int i = line - 1, j = pos - 1; i >= 1 && j >= 1; i--, j--)
        if (v[i][j])
            return false;

    for (int i = line - 1, j = pos + 1; i >= 1 && j <= N; i--, j++)
        if (v[i][j])
            return false;

    return true;
}

void dfs(int pos, int line)
{
    if (line == N)
    {
        answer++;
        return;
    }
    
    for (int i = 1; i <= N; i++)
    {
        if (isSafe(line + 1, i))
        {
            v[line + 1][i] = true;
            dfs(i, line + 1);
            v[line + 1][i] = false;
        }
    }
}

int main()
{
    cin >> N;

    v.assign(N + 1, vector<bool>(N + 1, false));

    for (int i = 1; i <= N; i++)
    {
        v[1][i] = true;
        dfs(i, 1);
        v[1][i] = false;
    }

    cout << answer << "\n";

    return 0;
}