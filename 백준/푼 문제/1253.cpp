#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int result = 0;

    int N;
    cin >> N;

    vector<int> v(N);

    for (int i = 0; i < N; i++)
        cin >> v[i];

    sort(v.begin(), v.end());

    for (int i = 0 ; i < N ; i++) {
        int cursor1 = 0;
        int cursor2 = N - 1;

        while (cursor1 < cursor2) {
            if(cursor1 == i) {
                cursor1++;
                continue;
            } 
            
            if(cursor2 == i) {
                cursor2--;
                continue;
            } 
            
            if (v[cursor1] + v[cursor2] < v[i])
                cursor1++;
            else if (v[cursor1] + v[cursor2] > v[i])
                cursor2--;
            else {
                result++;
                break;
            }
        }
    }

    cout << result << "\n";
}