#include <string>
#include <vector>
#include <stack>

using namespace std;

int solution(vector<int> order) {
    int answer = 0;

    int cursor = 0;
    stack<int> storage;
    int item = 0;

    while(item < 1000000) {
        ++item;
        if(item == order[cursor]) {
            cursor++;
        } else if(item < order[cursor]) {
            storage.push(item);
        } else {
            if(storage.size() > 0 && storage.top() == order[cursor]) {
                cursor++;
                storage.pop();
                --item;
                continue;
            }
            break;
        }
    }
    answer = cursor;
    return answer;
}