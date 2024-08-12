#include <string>
#include <vector>
#include <queue>

using namespace std;

void quickSort(vector<int> &arr, int start, int end) {
    if (start >= end) return;
    int pivot = start;
    int i = start + 1;
    int j = end;

    while (i <= j) {
        while (arr[i] <= arr[pivot])
            i++;
        
        while (arr[j] >= arr[pivot] && j > start)
            j--;
        
        if (i > j) {
            int temp = arr[j];
            arr[j] = arr[pivot];
            arr[pivot] = temp;
        } else {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

        quickSort(arr, start, j - 1);
        quickSort(arr, j + 1, end);
    }
}

long long solution(int n, vector<int> works) {
    long long answer = 0;

    priority_queue<int> pq;
    for(int work : works)
        pq.push(work);

    while(n-- > 0 && !pq.empty()) {
        int top = pq.top();
        pq.pop();
        top -= 1;
        if(top != 0)
            pq.push(top);
    }

    while(!pq.empty()) {
        int top = pq.top();
        pq.pop();
        answer += top * top;
    }
    return answer;
}