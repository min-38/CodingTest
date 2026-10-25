#include <string>
#include <vector>

using namespace std;

string solution(string my_string, string letter) {
    string answer = "";
    
    const int len = my_string.length();
    const char c = letter[0];
    
    for (char s : my_string)
        if (s != c)
            answer += s;

    return answer;
}
