#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
    int answer = 0;
    
    const int len = absolutes.size();
    
    for (int i = 0; i < len; i++)
    {
        int absolute = absolutes[i];
        if (!signs[i]) absolute *= -1;
        answer += absolute;
            
    }
    return answer;
}
