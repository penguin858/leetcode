#include <iostream>
#include <vector>
#include <iterator>
using namespace std;


// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int i = 1;
//         int j = nums.size();

//         auto it1 = nums.begin();
//         auto it2 = prev(nums.end());

//         while(true){
//             if(*it1 + *it2 == target){
//                 vector<int> v{i, j};
//                 return v;
//             }
//             else if(*it1 + *it2 > target){
//                 it2--;
//                 j--;
//             }
//             else{
//                 it1++;
//                 i++;
//             }
//         }
//         vector<int> v;
//         return v;
//     }
// };


class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size() - 1;

        while(true){
            if(nums[i] + nums[j] == target){
                vector<int> v{i+1, j+1};
                return v;
            }
            else if(nums[i] + nums[j] > target){
                j--;
            }
            else{
                i++;
            }
        }
        vector<int> v;
        return v;
    }
};
