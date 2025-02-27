#include <iostream>
#include <vector>

using namespace std;

static vector<int> parent;

int findParent(int x)
{
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]);
}

void unionFunc(int a, int b)
{
    a = findParent(a);
    b = findParent(b);

    if (a != b)
        parent[b] = a;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 도시의 수, 여행 계획에 속한 도시들의 수
    cin >> N >> M;

    int cities[201][201];
    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            cin >> cities[i][j];

    int path[1001];
    for (int i = 1; i <= M; i++)
        cin >> path[i];

    parent = vector<int>(N + 1);
    for (int i = 1; i <= N; i++)
        parent[i] = i;

    for (int i = 1; i <= N; i++)
        for (int j = 1; j <= N; j++)
            if (cities[i][j] == 1)
                unionFunc(i, j);

    int index = findParent(path[1]);
    bool connect = true;
    for (int i = 2; i <= M; i++)
        if (index != findParent(path[i]))
        {
            connect = false;
            break;
        }

    if (connect)
        cout << "YES\n";
    else
        cout << "NO\n";

    return 0;
}