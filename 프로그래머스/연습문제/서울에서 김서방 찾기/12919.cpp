#include <string>
#include <vector>

using namespace std;

string solution(vector<string> seoul) {
    string answer = "김서방은 ";
    
    const int len = seoul.size();
    for (int i = 0; i < len; i++)
    {
        const string s = seoul[i];
        if (s == "Kim")
        {
            answer += to_string(i) + "에 있다";
            break;
        }
    }

    return answer;
}
