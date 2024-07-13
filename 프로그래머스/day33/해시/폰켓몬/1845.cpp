#include <vector>
#include <map>
using namespace std;

int solution(vector<int> nums)
{
    int answer = 0;
    
    int limit = nums.size() / 2;
    map<int, int> m;
    for(int num : nums) {
        if(m.find(num) == m.end()) {
            m[num] = 1;
            answer++;
        }
        
        if(answer >= limit)
            break;
    }
    
    return answer;
}