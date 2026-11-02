#include <string>
#include <vector>
#include <cmath>

using namespace std;

int solution(int n) {
    int answer = 0;
    
    vector<int> v;
    
    // 3진법 만들기
    while (n > 0)
    {
        v.push_back(n % 3);
        n /= 3;
    }
    
    for (int d : v)
        answer = answer * 3 + d;
    
    return answer;
}
