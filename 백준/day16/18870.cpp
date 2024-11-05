#include <iostream>
#include <set>
#include <vector>
#include <iterator>

using namespace std;

int main() {
    // 시간 초과 방지용 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;
    vector<int> v(N, 0);
    set<int> s;

    for (int i = 0; i < N; i++) {
        cin >> v[i];
        s.insert(v[i]);
    }

    int idx;
    for(int i = 0; i < N; i++) {
        auto it = s.find(v[i]);
        cout << distance(s.begin(), it);
        if(i != N - 1)
            cout << " ";
    }

    cout << "\n";

    return 0;
}