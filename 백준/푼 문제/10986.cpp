#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N, M;
    cin >> N >> M;

    vector<long long> cnt(M, 0); 
    
    long long sum = 0;
    long long result = 0;

    for (int i = 0; i < N; i++) {
        int num;
        cin >> num;
        
        sum += num;
        int remainder = sum % M;
        
        if (remainder == 0)
            result++;
        
        cnt[remainder]++;
    }

    for (int i = 0; i < M; i++)
        if (cnt[i] > 1)
            result += (cnt[i] * (cnt[i] - 1)) / 2;

    cout << result << "\n";

    return 0;
}