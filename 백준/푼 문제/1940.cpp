#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, M; // 재료의 개수, 갑옷이 완성되는 번호의 합
    cin >> N >> M;

    vector<int> v(N + 1, 0);
    for(int i = 1; i <= N; i++) {
        cin >> v[i];
    }
    sort(v.begin(), v.end());

    int result = 0;
    int index1 = 1, index2 = N;
    while(index1 < index2) {
        if(v[index1] + v[index2] < M) {
            index1++;
        } else if(v[index1] + v[index2] > M) {
            index2--;
        } else {
            result++;
            index1++;
            index2--;
        }
    }
    cout << result << endl;
}