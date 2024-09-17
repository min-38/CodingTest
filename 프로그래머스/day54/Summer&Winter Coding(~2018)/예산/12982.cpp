#include <algorithm>
#include <vector>

using namespace std;

int solution(vector<int> d, int budget) {    
    sort(d.begin(), d.end());

    int i;
    for(i = 0; i < d.size(); i++) {
        if(d[i] > budget)
            break;
        budget -= d[i];
    }

    return i;
}