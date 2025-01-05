#include <iostream>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int N;
    cin >> N;

    int sum = 0;
    int M = 0;
    for(int i = 0; i < N; i++) {
        int score;
        cin >> score;
        
        sum += score;
        if(M < score)
            M = score;
    }

    double avg = sum * 100.0 / M / N;

    cout << avg << endl;

    return 0;
}