#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N = 3;
    vector<int> v(N, 0);

	for (int i = 0; i < N; i++)
		cin >> v[i];

    sort(v.begin(), v.end());

    cout << v[N / 2] << endl;

    return 0;
}