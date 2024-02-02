#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;
    vector<int> A(N, 0);

    for(int i = 0; i < N; i++) {
        cin >> A[i];
    }

    // insertion sort
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < i; j++) {
            if(A[j] > A[i]) {
                int temp = A[i];
                for(int k = i; k > j; k--) {
                    A[k] = A[k - 1];
                }
                A[j] = temp;
            }
        }
    }

    int sum = 0;
    for (int i = 0; i < N; i++) {
        for(int j = 0; j <= i; j++) {
            sum += A[j];
        }
    }
    cout << sum << endl;
}
