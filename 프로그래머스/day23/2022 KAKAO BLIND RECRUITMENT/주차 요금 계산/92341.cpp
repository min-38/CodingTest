#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

struct car {
    int car_num = -1;
    string enter;

    int total_time = 0;
    int total_fee = 0;
    int status = -1;
};

bool cmp(const car& a, const car& b)
{
    if (a.car_num < b.car_num) return true;
    return false;
}

int accumulate_parking_time(string enter, string exit) {
    int in_min = stoi(enter.substr(0, 2)) * 60 + stoi(enter.substr(3, 2));
    int out_min = stoi(exit.substr(0, 2)) * 60 + stoi(exit.substr(3, 2));

    return out_min - in_min;
}

vector<int> solution(vector<int> fees, vector<string> records) {
    vector<int> answer;
    
    vector<car> cars;
    int car_num; // 들어오는 차 번호
    string time; // 들어온 시간
    string in_out; // 들어오는 차량 내역
    int index;
    
    for(string s : records) {
        car c;
        
        time = s.substr(0, 5);
        car_num = stoi(s.substr(6, 4));
        in_out = s.substr(11, s.length() - 11);
        index = -1;
        
        // 차 번호가 car 벡터에 들어가있는지 확인
        for(int i = 0; i < cars.size(); i++)
            if(cars[i].car_num == car_num) {
                index = i;
                c = cars[i];
                break;
            }
        c.car_num = car_num;
        if(in_out == "IN") {
            c.status = 0;
            c.enter = time;
        } else {
            c.status = 1;
            c.total_time += accumulate_parking_time(c.enter, time);
        }
        
        if(index < 0)
            cars.push_back(c);
        else
            cars[index] = c;
    }
    sort(cars.begin(), cars.end(), cmp);
    
    for(car c : cars) {
        if(c.status == 0)
            c.total_time += accumulate_parking_time(c.enter, "23:59");

        c.total_fee = fees[1];
        if(c.total_time > fees[0]) {
            int over_time = c.total_time - fees[0];
            if(over_time % fees[2] != 0)
                c.total_fee += ((over_time/ fees[2]) + 1) * fees[3];    
            else
                c.total_fee += (over_time / fees[2]) * fees[3];
        }
        answer.push_back(c.total_fee);
    }
    return answer;
}