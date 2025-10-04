#include <iostream>
#include <vector>

using namespace std;

int N, M;
vector<int> v;

void dfs(int start, int depth)
{
    if (depth == M) {
        for (int i = 1; i <= M; i++) {
            cout << v[i] << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; i++)
    {
        v[depth + 1] = i;
        dfs(i, depth + 1);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin >> N >> M;

    v.assign(N + 1, 0);

    dfs(1, 0);
}