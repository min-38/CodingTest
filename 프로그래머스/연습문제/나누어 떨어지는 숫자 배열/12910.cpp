#include <string>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> arr, int divisor) {
    vector<int> answer;
    
    const int len = arr.size();

    for (int i = 0; i < len; i++)
    {
        int element = arr[i];
        if (element % divisor == 0)
            answer.push_back(element);
    }
    
    if (answer.size() == 0)
        answer.push_back(-1);
    else
        sort(answer.begin(), answer.end());
    
    return answer;
}
