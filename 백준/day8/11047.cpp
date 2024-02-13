#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N, K;
    cin >> N >> K;

    vector<int> V(N);

    for (int i = 0; i < N; i++) {
        cin >> V[i];
    }

    
    int result = 0;
    for(int i = N - 1; i >= 0; i--) {
        if(K == 0) break;
        else {
            if(V[i] > K) continue;
            else {
                K -= V[i];
                result++;
                i++;
            }
        }
    }

    cout << result << endl;
    return 0;
}