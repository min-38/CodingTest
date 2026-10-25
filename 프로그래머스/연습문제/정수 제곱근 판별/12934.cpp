#include <string>
#include <vector>
#include <cmath>

using namespace std;

long long solution(long long n) {    
    long long sqrtn = sqrt(n);
    if (n != sqrtn * sqrtn)
        return -1;
    sqrtn += 1;
    
    return sqrtn * sqrtn;
}
