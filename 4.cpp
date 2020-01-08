#include <iostream>

using namespace std;

/*
 * 4. Median of Two Sorted Arrays
 * Given two sorted arrays, find out the median of the two arrays.
 * 
 * This question can be seen as finding a separation like :
 *   left part        |   right part
 * A[0], ... , A[i-1] | A[i], ... , A[m-1]
 * B[0], ... , B[j-1] | B[j], ... , B[n-1]
 * 
 * The saperation should satisfy: i + j == sum_len / 2 AND A[i-1] <= B[j] AND B[j-1] <= A[i] 
 * Then : m = max(A[i-1], B[j-1]) if sum_len is odd  OR  m = (max(A[i-1], B[j-1])  + min(A[i], B[j])) / 2 if sum_len is even.
 * 
 * In this question, use binary search to find i, the complexity can be O(log(m))
 * 
 * Marginal cases: ensure nums1 is the shorter one.
 *  1. if i = 0
 *  2. if j = 0
*/

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        if(nums2.size() < nums1.size()){
            auto swap = nums1;
            nums1 = nums2;
            nums2 = swap;
        }
        int sum_len = nums1.size() + nums2.size();
        int half_len = (sum_len + 1) / 2;
        int mini = 0, maxi = nums1.size() , i = 0;
        int j = half_len - i;
        int max_left, min_right;

        while(mini <= maxi){
            i = (mini + maxi) / 2;
            j = half_len - i;
            
            if(i > 0  && nums1[i-1] > nums2[j]){  // move i towards left
                maxi = i - 1;
            }
            else if(i < nums1.size()  && nums2[j-1] > nums1[i]){ // move i towalds right
                mini = i + 1;
            }
            else{
                if(i == 0)
                    max_left = nums2[j-1];
                else if(j == 0)
                    max_left = nums1[i-1];
                else
                    max_left = max(nums2[j-1], nums1[i-1]);
        
                if(sum_len % 2){
                    return max_left;
                }
                else{
                    if(i == nums1.size())
                        min_right = nums2[j];
                    else if(j == nums2.size())
                        min_right = nums1[i];
                    else
                        min_right = min(nums2[j], nums1[i]);
            
                return (max_left + min_right) / 2.0;
                }
            }
        }
        return 0;
        
    }
};