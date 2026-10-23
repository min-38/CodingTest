#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer;
    
    int list_size = num_list.size();
    
    for (int i = 1; i <= list_size; i++)
        answer.push_back(num_list[list_size - i]);

    return answer;
}
