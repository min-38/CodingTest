#include <iostream>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int n, min = -1, max = -1;
    cin >> n;
    int num;
    for (int i = 0; i < n; i++) {
        cin >> num;
        
        if (min == -1 || num < min) {
            min = num;
        }

        if (max == -1 || num > max) {
            max = num;
        }
    }

    cout << min * max << '\n';

    return 0;
}