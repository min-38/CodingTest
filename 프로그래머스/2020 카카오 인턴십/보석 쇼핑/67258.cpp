#include <bits/stdc++.h>
using namespace std;

vector<int> solution(vector<string> gems) {
    vector<int> answer = {0, INT_MAX};
    
    // 진열된 보석 개수
    const int n = gems.size();
    
    // 보석 종류 개수
    unordered_set<string> us(gems.begin(), gems.end());
    const int need = us.size();
    
    if (need <= 1)
        return vector<int>{1, 1};
    
    // 가지고 있는 각 보석의 개수를 저장하기 위한 map
    unordered_map<string, int> um;
    
    // 가지고 있는 보석 개수
    int have = 0;
    
    // 왼쪽 포인터
    int L = 0;
    int bestL = 0, bestR = n - 1;
    bool found = false;
    
    // 오른쪽 포인터를 이동시키며
    for (int R = 0; R < n; ++R)
    {
        // 1개를 가지게 되면 처음 가지게 되는 보석이므로 have 추가
        if (++um[gems[R]] == 1) ++have;
        
        // 필요한 보석 개수를 가지고 있으며 현재 왼쪽 포인터의 보석 개수가 1개 이상이라면 오른쪽으로 이동
        while (have == need && um[gems[L]] > 1)
        {
            --um[gems[L]];
            ++L;
        }

        // 필요한 보석 개수를 다 가지고 있으면
        if (have == need)
            if ((answer[1] - answer[0]) > (R - L) || ((answer[1]  - answer[0]) == (R - L) && L < answer[0])) {
                answer[0] = L + 1;
                answer[1] = R + 1;
            }
        
    }
    
    return answer;
}
