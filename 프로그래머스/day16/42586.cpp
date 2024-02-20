#include <string>
#include <vector>
#include <queue>

using namespace std;

vector<int> solution(vector<int> progresses, vector<int> speeds) {
    vector<int> answer;
    
    queue<int> q;
    int count = 0;
    while(count < progresses.size()) {
        while(!q.empty()) q.pop();
        
        for(int i = count; i < speeds.size(); i++) {
            progresses[i] += speeds[i];
            q.push(progresses[i]);
        }

        int result = 0;
        while(q.size() > 0 && q.front() >= 100) {
            q.pop();
            result++;
            count++;
        }
        if(result > 0) answer.push_back(result);
    }
    
    return answer;
}