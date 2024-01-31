#include <iostream>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> wallpaper) {
    vector<int> answer;
    
    int lux = 50, luy = 50, rdx = 0, rdy = 0;
    for(int i = 0; i < wallpaper.size(); i++) {
        string line = wallpaper[i];

        for(int j = 0; j < line.length(); j++) {
            if(line[j] == '#') {
                if(j <= lux) {
                    lux = j;
                }
                if(i <= luy) {
                    luy = i;
                }
                if(j + 1 >= rdx) {
                    rdx = j + 1;
                }
                if(i + 1 >= rdy) {
                    rdy = i + 1;
                }
            }
        }
    }

    answer.push_back(luy);
    answer.push_back(lux);
    answer.push_back(rdy);
    answer.push_back(rdx);
    return answer;
}