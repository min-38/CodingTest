#include <string>
#include <vector>

using namespace std;

void change(vector<int>& a, vector<int>& b) {
    vector<int> tmp;
    tmp = a;
    a = b;
    b = tmp;
}

int solution(vector<vector<int>> data, int col, int row_begin, int row_end) {
    int answer = -1;
    
    bool sorted = false;
    while(!sorted) {
        sorted = true;
        for(int i = 1; i < data.size(); i++)
            if(data[i][col - 1] < data[i - 1][col - 1]
                || (data[i][col - 1] == data[i - 1][col - 1] && data[i][0] > data[i - 1][0])
            ) {
                change(data[i], data[i - 1]);
                sorted = false;
            }
    }

    for(int i = row_begin - 1; i <= row_end - 1; i++) {
        int s_i = 0;
        for(int j = 0; j < data[i].size(); j++)
            s_i += data[i][j] % (i + 1);

        if(answer == -1)
            answer = s_i;
        else
            answer ^= s_i;
    }

    return answer;
}