#include <vector>
#include <iostream>
#include <cmath>

using namespace std;

bool isPrime(int n) {
	for (int i = 2; i * i <= n; i++)
		if (n % i == 0)
			return false;
	return true;
}

int solution(vector<int> nums) {
    int answer = 0;
    
    int size = nums.size();
    for (int i = 0; i < size; i++)
        for (int j = i + 1; j < size; j++)
            for (int k = j + 1; k < size; k++)
                if (isPrime(nums[i] + nums[j] + nums[k]))
                    answer++;

    return answer;
}
