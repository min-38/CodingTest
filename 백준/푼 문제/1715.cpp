#include <iostream>
#include <queue>
#include <functional>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    priority_queue<int, vector<int>, greater<int>> pq;

    int N; // 카드의 묶음
    cin >> N;

    for(int i = 0; i < N; i++) {
        int cards;
        cin >> cards;

        pq.push(cards);
    }

    int result = 0;

    while(pq.size() > 1) {
        int a = pq.top();
        pq.pop();

        int b = pq.top();
        pq.pop();

        pq.push(a + b);
        result += a + b;
    }

    cout << result << endl;

    return 0;
}