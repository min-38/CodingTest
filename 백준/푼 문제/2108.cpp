#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int N;
    cin >> N;

    vector<int> v(N);
    int cnt[8001] = {0, };
    
    int max_cnt = 0; 
    double sum = 0;

    for (int i = 0; i < N; i++)
    {
        cin >> v[i];
        sum += v[i];
        
        cnt[v[i] + 4000]++;
    }

    for(int i=0; i<8001; i++)
        if(cnt[i] > max_cnt)
            max_cnt = cnt[i];


    sort(v.begin(), v.end());

    // 산술 평균
    cout << (int)round(sum / N) << "\n"; 
    
    // 중앙값
    cout << v[N / 2] << "\n";
    
    // 최빈값
    int mode = 0;
    bool flag = false; 
    for (int i = 0; i < 8001; i++)
    {
        if (cnt[i] == max_cnt)
        {
            if (flag)
            {
                mode = i - 4000;
                break;
            }
            mode = i - 4000;
            flag = true;
        }
    }
    cout << mode << "\n";

    // 범위
    cout << v.back() - v.front() << "\n";
    
    return 0;
}