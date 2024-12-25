#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strArr) {
    vector<string> answer;
    
    bool adExist = false;
    for(int i = 0; i < strArr.size(); i++) {
        adExist = false;
        for(int j = 0; j < strArr[i].length(); j++)
            if(strArr[i][j] == 'a' && strArr[i][j + 1] == 'd') {
                adExist = true;
                break;
            }
        
        if(!adExist)
            answer.push_back(strArr[i]);
    }

    return answer;
}