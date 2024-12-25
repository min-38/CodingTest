#include <string>
#include <vector>
#include <cmath>

using namespace std;

vector<vector<int>> v = {{1,2,3}, {4,5,6}, {7,8,9}, {-1,0,-2}};

void calculate(string &answer, int number, string hand, int lh[], int rh[]) {
    for (int y = 0; y < v.size(); y++) {
        for (int x = 0; x < v[y].size(); x++) {
            if (v[y][x] == number) {
                if (x == 0) {
                    answer += "L";
                    lh[0] = y;
                    lh[1] = x;
                } else if (x == v[y].size() - 1) {
                    answer += "R";
                    rh[0] = y;
                    rh[1] = x;
                } else {
                    int lh_dist = abs(x - lh[1]) + abs(y - lh[0]);
                    int rh_dist = abs(x - rh[1]) + abs(y - rh[0]);
                    if (lh_dist < rh_dist) {
                        answer += "L";
                        lh[0] = y;
                        lh[1] = x;
                    } else if (lh_dist > rh_dist) {
                        answer += "R";
                        rh[0] = y;
                        rh[1] = x;
                    } else {
                        if(hand == "left") {
                            answer += "L";
                            lh[0] = y;
                            lh[1] = x;
                        } else {
                            answer += "R";
                            rh[0] = y;
                            rh[1] = x;
                        }
                    }
                }
                return;
            }
        }
    }
}

string solution(vector<int> numbers, string hand) {
    string answer = "";

    int lh[2] = {3, 0}; // y, x
    int rh[2] = {3, 2}; // y, x

    for(int number : numbers)
        calculate(answer, number, hand, lh, rh);
    
    return answer;
}