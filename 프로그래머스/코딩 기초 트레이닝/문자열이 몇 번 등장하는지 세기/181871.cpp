#include <string>
#include <vector>

using namespace std;

int solution(string myString, string pat) {
    int answer = 0;
    
    for(int i = 0; i < myString.length(); i++) {
        if(myString.length() - i < pat.length())
            break;
        
        string s = "";
        for(int j = 0; j < pat.length(); j++)
            s += myString[i + j];
        
        if(s == pat)
            answer++;
    }
    return answer;
}