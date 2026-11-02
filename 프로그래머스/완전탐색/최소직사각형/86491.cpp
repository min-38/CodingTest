#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<vector<int>> sizes) {
    int max_w = 0, max_h = 0;

    for (const vector<int>& v : sizes) {
        max_w = max(max_w, max(v[0], v[1]));
        max_h = max(max_h, min(v[0], v[1]));
    }

    return max_w * max_h;
}
