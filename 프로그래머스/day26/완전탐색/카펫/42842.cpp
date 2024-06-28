#include <string>
#include <vector>

using namespace std;

vector<int> solution(int brown, int yellow) {
    vector<int> answer;
    
    int tiles = brown + yellow;
    for(int i = tiles; i > 0; i--)
        if(tiles % i == 0)
        {
            int x = i;
            int y = tiles / i;
            
            if(x < y)
                break;
            
            if((x - 2) * (y - 2) == yellow)
            {
                answer.push_back(x);
                answer.push_back(y);
            }
        }
    
    return answer;
}