#include <iostream>
#include <vector>
#include <iterator>
using namespace std;

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int indexi = 0;
//         for(auto i = nums.begin(); i != nums.end(); i++){
//             int indexj = indexi + 1;
//             for(auto j = next(i); j != nums.end(); ++j){
//                 if(*j + *i == target){
//                     vector<int> v;
//                     v.push_back(indexi);
//                     v.push_back(indexj);
//                     return v;
//                 }
//                 indexj++;
//             }
//             indexi++;
//         }
//         vector<int> v;
//         return v;
//     }
// };

/*
 *
 * This is a memory-efficient method
 * 
 */
// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
//         int indexi = 0;
//         for(vector<int>::iterator i = nums.begin(); i != nums.end(); i++){
//             int indexj = indexi + 1;
//             for(vector<int>::iterator j = next(i); j != nums.end(); ++j){
//                 if(*j + *i == target){
//                     vector<int> v;
//                     v.push_back(indexi);
//                     v.push_back(indexj);
//                     return v;
//                 }
//                 indexj++;
//             }
//             indexi++;
//         }
//         vector<int> v;
//         return v;
//     }
// };

/*
 * A better method
 */

// class Solution {
// public:
//     vector<int> twoSum(vector<int>& nums, int target) {
        // int len = nums.size();
        // int a[len];
        // int index = 0;
        // for(auto i = nums.begin(); i != nums.end(); i++){
        //     a[index] = *i;
        //     index++;
        // }

//         for(int i = 0 ; i < len ; i++){
//             for(int j = i + 1 ; j < len; j++){
                // if(a[i] + a[j] == target){
                //     vector<int> v;
                //     v.push_back(i);
                //     v.push_back(j);
                //     return v;
//                 }
//             }
//         }
//         vector<int> v;
//         return v;
//     }
// };

/*
 * Best solution
*/

struct Value{
    int val;
    int index;
    Value(int val, int index){
        this->val = val;
        this->index = index;
    }
    Value(){}
};

bool cmp(Value a, Value b){
    return a.val < b.val;
}

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int len = nums.size();
        Value a[len];
        int index = 0;
        for(auto i = nums.begin(); i != nums.end(); i++){
            a[index] = Value(*i, index);
            index++;
        }

        sort(a, a + len, cmp);

        for(int i = 0 ; i < len; i++){
            for(int j = i + 1 ; j < len ; j++){
                if(a[i].val + a[j].val == target){
                    vector<int> v;
                    v.push_back(a[i].index);
                    v.push_back(a[j].index);
                    return v;
                }
                else if(a[i].val + a[j].val > target)
                    break;
            }
        }
        vector<int> v;
        return v;
    }
};

