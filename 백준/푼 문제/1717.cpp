#include <iostream>
#include <vector>

using namespace std;

const int MAX = 1000000;

vector<int> parent(MAX + 1);

int findParent(int x) {
    if (parent[x] == x)
        return x;
    return parent[x] = findParent(parent[x]); 
}

void unionFunc(int a, int b)
{
    a = findParent(a);
    b = findParent(b);
    
    if (a == b) return;
    else if (a > b) parent[b] = a;
    else parent[a] = b;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, m;
    cin >> n >> m;

    for (int i = 1; i <= n; i++)
        parent[i] = i;

    for (int i = 0; i < m; i++)
    {
        int type, a, b;
        cin >> type >> a >> b;

        if (type == 0)
            unionFunc(a, b);
        else
        {
            if (findParent(a) == findParent(b))
                cout << "YES" << "\n";
            else
                cout << "NO" << "\n";
        }
    }

    return 0;
}