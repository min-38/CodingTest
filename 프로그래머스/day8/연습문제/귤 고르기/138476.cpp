#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;

    sort(tangerine.begin(), tangerine.end());

    int big_tangerine = tangerine[tangerine.size() - 1];
    vector<int> A(big_tangerine + 1, 0);
    for(int t : tangerine) {
        A[t]++;
    }

    sort(A.rbegin(), A.rend());
    
    int sum = 0;
    for(int t : A) {
        sum += t;
        answer++;
        if(sum >= k) {
            break;
        }
    }

    return answer;
}