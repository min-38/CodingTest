#include <string>
#include <vector>

using namespace std;

string solution(string phone_number) {
    const int limit = phone_number.length() - 4;
    
    for (int i = 0; i < limit; i++)
        phone_number[i] = '*';

    return phone_number;
}
