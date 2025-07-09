#include <string>
#include <vector>

using namespace std;

bool check(int i, int j, vector<string> place)
{
    int dx[4] = { -1, 1, 0, 0 };
    int dy[4] = { 0, 0, 1, -1 };
    int findP = 0;
    int nextx;
    int nexty;
    
    for (int h = 0; h < 4; h++)
    {
        nexty = i + dx[h];
        nextx = j + dy[h];
            
        if (nexty >= 0 && nexty <= 4 && nextx >= 0 && nextx <= 4)
        {
            if (place[nexty][nextx] == 'P')
            {
                findP++;
            }

            if (place[i][j] == 'O')
            {
                if (findP == 2) return false;
            }
            else
            {
                if (findP) return false;
            }
        }
    }
    
    return true;
}

vector<int> solution(vector<vector<string>> places) {
    vector<int> answer;
    bool check_dist = true;
    
    for (const auto& place : places) {
        for (int i = 0; i < 5 && check_dist; i++)
        {
            for (int j = 0; j < 5 && check_dist; j++)
            {
                if (place[i][j] != 'X')
                    check_dist = check(i, j, place);
            }
        }
        
        if (check_dist)
            answer.push_back(1);
        else
            answer.push_back(0);
        
        check_dist = true;
    }
    
    return answer;
}