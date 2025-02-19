#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N, M;
vector<int> v;

int BS(const int target) { // Binary Search
    // 이진 탐색 시작
    int start = 0;
    int end = v.size() - 1;

    while (start <= end) {
        int midx = (start + end) / 2;
        int value = v[midx];

        if (value > target) {
            end = midx - 1;
        } else if (value < target) {
            start = midx + 1;
        } else {
            return 1;
        }
    }

    return 0;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> N;
    v = vector<int>(N);

    for(int i = 0; i < N; i++) {
        cin >> v[i];
    }

    sort(v.begin(), v.end());
    cin >> M;

    for(int i = 0; i < M; i++) {
        int target;
        cin >> target;

        cout << BS(target) << "\n";
    }
}
