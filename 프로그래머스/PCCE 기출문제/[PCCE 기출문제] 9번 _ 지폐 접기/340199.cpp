#include <string>
#include <vector>

using namespace std;

int solution(vector<int> wallet, vector<int> bill) {
    int answer = 0;
    
    int wW = wallet[0];
    int wH = wallet[1];
    int wMax = max(wW, wH);
    int wMin = min(wW, wH);
    
    
    int bW = bill[0];
    int bH = bill[1];
    int bMax = max(bW, bH);
    int bMin = min(bW, bH);
    
    while (bMin > wMin || bMax > wMax)
    {
        if (bW > bH)
            bW /= 2;
        else
            bH /= 2;
        
        bMax = max(bW, bH);
        bMin = min(bW, bH);
        
        answer++;
    }
    
    return answer;
}
