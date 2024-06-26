#include <string>
#include <vector>

using namespace std;

int solution(vector<int> arr) {
    int answer = 0;
    
    int result = 1;
    int limit = 0;
    for(int i = 0; i < arr.size(); i++)
        if(limit < arr[i])
            limit = arr[i];

    int divide = 2;
    while(divide <= limit)
    {
        int cnt = 0;
        for(int i = 0; i < arr.size(); i++)
            if((arr[i] % divide) == 0)
                cnt++;
        
        if(cnt > 1)
        {
            for(int i = 0; i < arr.size(); i++)
                if((arr[i] % divide) == 0)
                    arr[i] = arr[i] / divide;
            result *= divide;
        }
        else
            divide++;
    }

    for(int i = 0; i < arr.size(); i++)
        result *= arr[i];
    
    answer = result;
    return answer;
}