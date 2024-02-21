#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> prices) {
    vector<int> answer;
    
    queue<int> q;
    for(int i = 0; i < prices.size(); i++) {        
        for(int j = i + 1; j < prices.size(); j++) {
            q.push(prices[j]);
            if(prices[i] > prices[j]) {
                break;
            }
        }
        answer.push_back(q.size());
        
        while(!q.empty()) q.pop();
    }
    return answer;
}