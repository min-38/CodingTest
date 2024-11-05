#include <iostream>
#include <map>

using namespace std;

int main() {
    // 시간 초과 방지용 코드
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M = 0;
    map<int, int> m;

    int num = 0;
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> num;
        m[num]++;
    }

    int result;
    cin >> M;
    for (int i = 0; i < M; i++) {
        result = 0;
        cin >> num;
        if (m[num] > 0)
            result = 1;
        
        printf("%d ", result);
    }
    printf("\n");

    return 0;
}