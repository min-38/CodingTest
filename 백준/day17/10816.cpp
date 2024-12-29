#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    // 시간 초과 방지용 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N;

    map<int, int> m;

    int value = 0;
    for (int i = 0; i < N; i++) {
        cin >> value;
        m[value]++;
    }

    cin >> M;
    for (int i = 0; i < M; i++) {
        cin >> value;
        if (m[value] > 0)
            cout << m[value];
        else
            cout << 0;
        cout << " ";
    }
    cout << "\n";

    return 0;
}