#include <iostream>
#include <queue>

using namespace std;

struct cmp {
    bool operator()(int a, int b) {
        int ab = abs(a);
        int bb = abs(b);
        if(ab == bb) {
            return a > b;
        }
        return ab > bb;
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    priority_queue<int, vector<int>, cmp> pq;
    
    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        if (num != 0)
            pq.push(num);
        else {
            int value = 0;
            if (pq.size() > 0) {
                value = pq.top();
                pq.pop();
            }
            cout << value << endl;
        }
    }
    return 0;
}