#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<pair<int, int> > A(N);

    for(int i = 0; i < N; i++) {
        cin >> A[i].first;
        A[i].second = i;
    }

    sort(A.begin(), A.end()); // 배열 A 정렬 시간 복잡도: O(nlogn)
    int Max = 0;

    for(int i = 0; i < N; i++) {
        // 정렬 전 index - 정렬 후 index를 계산한 값 중 최댓값을 찾아 저장
        if(Max < A[i].second - i) {
            Max = A[i].second - i;
        }
    }
    cout << Max + 1 << endl;
    return 0;
}