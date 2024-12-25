#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

// 전화번호부를 저장하기 위한 해시맵
unordered_map<string, int> phoneBook;

// 번호가 접두어인지 확인하는 함수
bool isPrefix(const string& phoneNumber) {
    string prefix = "";
    for(char digit : phoneNumber) {
        prefix += digit;
        // 현재 접두어가 전화번호부에 있고 현재 번호와 같이 않다면 = 접두어
        if(phoneBook.find(prefix) != phoneBook.end() && prefix != phoneNumber)
            return true;
    }
    // 접두어가 아니면 false 반환
    return false;
}

bool solution(vector<string> phoneNumbers) {
    // 전화번호부를 해시맵에 저장
    for(const string& phoneNumber : phoneNumbers)
        phoneBook[phoneNumber] = 1;

    // 각 전화번호가 접두어인지 확인
    for(const string& phoneNumber : phoneNumbers)
        if(isPrefix(phoneNumber))
            return false;

    return true;
}