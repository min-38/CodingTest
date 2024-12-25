#include <string>
#include <vector>

using namespace std;

int solution(vector<int> ingredient) {
    int answer = 0;
    vector<int> v;

    for(int i : ingredient) {
        v.push_back(i);
        if(i == 1 && v.size() >= 4) {
            if(v[v.size() - 2] == 3 && v[v.size() - 3] == 2 && v[v.size() - 4] == 1) {
                answer++;
                v.pop_back();
                v.pop_back();
                v.pop_back();
                v.pop_back();
            }
        }
    }

    return answer;
}