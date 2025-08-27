#include <iostream>
#include <vector>

using namespace std;
int main() {
    int T; // testcase
    cin >> T;

    vector<int> charge = {25, 10, 5, 1}; // 거스름돈

    for (int t = 0; t < T; t++) {
        vector<int> result(4, 0);

        // C의 단위는 센트이다. (1달러 = 100센트)
        int C;
        cin >> C;

        for (int i = 0; i < charge.size(); i++) {
            if (C >= charge[i]) {
                result[i] = C / charge[i];
                C = C % charge[i];
            }
        }

        for (int i = 0; i < result.size(); i++)
            cout << result[i] << " ";
        cout << endl;
    }

    return 0;
}