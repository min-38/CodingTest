#include <string>
#include <vector>

using namespace std;

long long solution(int cap, int n, vector<int> deliveries, vector<int> pickups) {
    long long answer = 0;
    
    int delivery_need = 0;
    int pickup_need = 0;
    
    for (int i = n - 1; i >= 0; i--)
    {
        delivery_need += deliveries[i];
        pickup_need += pickups[i];
        
        while (delivery_need > 0 || pickup_need > 0)
        {
            answer += (long long)(i + 1) * 2;
    
            delivery_need -= cap;
            pickup_need -= cap;
        }
    }
    
    return answer;
}