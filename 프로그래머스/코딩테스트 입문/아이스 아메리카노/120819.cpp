#include <string>
#include <vector>

using namespace std;

vector<int> solution(int money) {
    vector<int> answer;
    
    const int americano_cost = 5500;
    
    answer.push_back(money / americano_cost);
    answer.push_back(money % americano_cost);

    return answer;
}
