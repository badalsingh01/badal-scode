#include<iostream>
#include<vector>
#include<deque>
using namespace std;

void maxSubArrayK(vector<int> a, int k) {

    int n = a.size();
    deque<int> q(k);
    int i;

    for(i = 0; i < k; i++) {

        while(!q.empty() && a[i] > a[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }

    for(;i<n;i++) {
        cout << a[q.front()] << " ";
        while(!q.empty() && q.front() <= i - k) {
            q.pop_front();
        }
        while(!q.empty() && a[i] > a[q.back()]) {
            q.pop_back();
        }
        q.push_back(i);
    }
    cout << a[q.front()] << endl;
}
int main() {
    
    vector<int> arr{1,2,3,1,4,5,2,3,5};
    int k = 3;

    maxSubArrayK(arr,k);


    
    
    return 0;
}