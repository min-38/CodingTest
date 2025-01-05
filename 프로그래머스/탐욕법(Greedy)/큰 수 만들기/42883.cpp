#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    string answer = "";
    
    int n = number.length();
    int startIdx = 0;
    for (int i = 0; i < n - k; i++) {
        char maxNumber = number[startIdx];
        int maxIdx = startIdx;
        
        for (int j = startIdx + 1; j <= k + i; j++) {
            if (maxNumber < number[j]) {
                maxNumber = number[j];
                maxIdx = j;
            }
        }
        
        startIdx = maxIdx + 1;
        answer += maxNumber;
    }

    return answer;
}