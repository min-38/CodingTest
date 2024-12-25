#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> citations) {
    int answer = 0;
    
    int n = citations.size();
    
    sort(citations.begin(), citations.end());
    
    int ref, hidx;
    for(int i = 0; i < citations.size() - 1; i++) {
        ref = n - i;
        hidx = min(citations[i], ref);
        if (answer < hidx)
            answer = hidx;
    }
    
    return answer;
}