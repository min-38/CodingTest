#include <string>
#include <vector>

using namespace std;

int solution(int n, int t) {
    int answer = 0;
    
    for(int i = 1; i <= t; i++)
        n += n;

    answer = n;
    return answer;
}