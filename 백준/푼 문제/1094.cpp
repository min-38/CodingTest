#include <iostream>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int X;
    cin >> X;

    int result = 0;
    while (X > 1) {
        if (X % 2 == 1)
            result++;
        X /= 2;
    }

    if (X == 1)
        result++;

    cout << result << endl;

    return 0;
}