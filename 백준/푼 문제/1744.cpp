#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N; // 카드 묶음 수
    cin >> N;
    priority_queue<int, vector<int>, greater<int> > pq; // 오름차순 정렬
    int data;

    for (int i = 0; i < N; i++) {
        cin >> data;
        pq.push(data);
    }

    int data1 = 0;
    int data2 = 0;
    int result = 0;

    while(pq.size() != 1) {
        data1 = pq.top();
        pq.pop();
        data2 = pq.top();
        pq.pop();
        if((data1 < 0 && data2 < 0) || (data1 > 1 && data2 > 1)) {
            result += data1 * data2;
        } else {
            result += data1 + data2;
        }
        // pq.push(data1 + data2);
    }

    cout << result << endl;

    return 0;
}