#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> players, int m, int k) {
    int answer = 0;
    
    int running_server = 0;
    queue<pair<int, int>> time; // 반납 시간, 서버 수
    
    for(int i = 0; i < players.size(); ++i)
    {
        if(!time.empty() && time.front().first == i)
        {
            running_server -= time.front().second;
            time.pop();
        }
        
        if(m <= players[i])
        {
            int required = players[i] / m;  // 필요한 서버 수 계산
            
            if (required > running_server)
            {
                int new_server = required - running_server;
                running_server += new_server;
                answer += new_server;
                time.push({i + k, new_server});
            }
        }
    }
    
    return answer;
}