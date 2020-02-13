#include <iostream>
#include <vector>
using namespace std;

/**
 * 974. Subarray Sums Divisible by K
 * Given an array A of integers, return the number of (contiguous, non-empty) subarrays that have a sum divisible by K.
 * 
 * First Idea: Use two pointers to record the start point and end point. Use a variable to store temporary sum.(The same to sliding window question)
 * This solution will be out of time limitation.
 * 
*/

class Solution {
public:
    int subarraysDivByK(vector<int>& A, int K) {
        int cnt = 0, sum = 0, n = A.size();
        for(int j = 0 ; j < n; j++){
            sum = A[j];
            for(int i = j - 1; i >= 0 ; i--){
                if(sum % K == 0)
                    cnt++;
                sum += A[i];
            }
            if(sum % K == 0)
                cnt++;
        }
        return cnt;
    }
};