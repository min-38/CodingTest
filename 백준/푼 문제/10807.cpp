#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int N;
    cin >> N;

    vector<int> arr(201, 0);
    for (int i = 0; i < N; i++)
    {
        int m;
        cin >> m;
        arr[m + 100] += 1;
    }

    int v;
    cin >> v;
    cout << arr[v + 100] << endl;

    return 0;
}
