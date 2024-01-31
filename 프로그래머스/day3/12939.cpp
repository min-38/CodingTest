#include <string>
#include <vector>

using namespace std;

string solution(string s) {
    int max, min = 0;
    
    string s_value = "";
    int count = 0;
    for(int i = 0; i < s.length(); i++) {
        if(s[i] != ' ') {
            s_value += s[i];
            if(i != s.length() -1) continue;
        }

        int i_value = stoi(s_value);
        if(count == 0) {
            max = i_value;
            min = i_value;
            count++;
        } else {
            if(i_value > max)
                max = i_value;
            else if(i_value < min)
                min = i_value;
        }
        s_value = "";
    }
    
    string answer = to_string(min) + " " + to_string(max);
    return answer;
}