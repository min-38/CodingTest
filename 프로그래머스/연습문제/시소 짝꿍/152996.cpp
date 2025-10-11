#include <string>
#include <vector>
#include <map>

using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    
    map<int, long long> m;
    for (int weight : weights)
        m[weight]++;
    
    for (auto const& [weight, count] : m)
    {
        if (count > 1)
            answer += count * (count - 1) / 2;
        
        int w = weight;
        if ((w * 3) % 2 == 0)
        {
            if (m.count((w * 3) / 2))
            {
                answer += count * m[(w * 3) / 2];
            }
        }
        
        if (m.count(w * 2))
            answer += count * m[w * 2];

        if ((w * 4) % 3 == 0)
        {
            if (m.count((w * 4) / 3))
            {
                answer += count * m[(w * 4) / 3];
            }
        }
    }
    
    return answer;
}
