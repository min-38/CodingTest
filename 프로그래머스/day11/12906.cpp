#include <vector>
#include <iostream>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    vector<int> answer;
    
    for(int i : arr) {
        if(answer.size() == 0 || answer.back() != i)
            answer.push_back(i);
    }

    return answer;
}