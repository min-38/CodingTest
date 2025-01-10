#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int max = -1;
    int N;
    cin >> N;

    vector<int> v(N, -1);
    vector<int> A, B;

    int num;
    for (int i = 0; i < N; i++) {
        cin >> num;
        while (A.size() > 0 && A.back() < num) {
            A.pop_back(); 
            v[B.back()] = num;
            B.pop_back();
        }
        A.push_back(num);
        B.push_back(i);
    }

    for (int i = 0; i < N; i++)
        cout << v[i] << " ";

    return 0;
}