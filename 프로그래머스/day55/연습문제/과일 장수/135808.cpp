#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
    
    sort(score.rbegin(), score.rend());
    
    int index = m - 1;
    for(int i = 0; i < score.size() / m; i++) {
        if(score.size() - i * m < m)
            break;
    
        answer += score[index] * m;
        index += m;
    }
    
    return answer;
}