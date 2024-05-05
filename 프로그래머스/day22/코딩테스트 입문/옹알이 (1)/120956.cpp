#include <string>
#include <vector>

using namespace std;

int solution(vector<string> babbling) {
    int answer = 0;
    
    for(string s : babbling) {
        string word = "";
        for(char c : s) {
            word += c;
            if(word == "aya" || word == "ye" || word == "woo" || word == "ma")
                word = "";
        }
        
        if(word == "")
            answer++;
    }
    return answer;
}