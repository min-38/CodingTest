#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

string solution(vector<int> numbers) {
    string answer = "";

    vector<string> v;
    for(int number : numbers)
        v.push_back(to_string(number));

    sort(v.begin(), v.end(), [](const string& a, const string& b) {
        return stoi(a + b) > stoi(b + a);
    });

    for(string s : v)
        answer += s;
    
    if(answer[0] == '0')
        answer = "0";

    return answer;
}