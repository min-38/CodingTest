#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    
    // two pointer algorithm
    sort(people.begin(), people.end());
    int start = 0;
    int end = people.size() - 1;

    while(start <= end) {
        if(people[end] + people[start] <= limit) {
            start++;
            end--;
        } else {
            end--;
        }
        answer++;
    }

    return answer;
}