#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
    
    while (storey > 0)
    {
        int lastDigit = storey % 10;
        int nextDigit = (storey / 10) % 10;
        
        if (lastDigit > 5 || (lastDigit == 5 && nextDigit >= 5))
            storey += 10 - lastDigit; 
        else
            storey -= lastDigit; 
        
        storey /= 10;
        
        answer += min(lastDigit, 10 - lastDigit); 
    }

    return answer;
}