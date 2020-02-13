#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 * 
 * 136. Single Number
 * Given a non-empty array of integers, every element appears twice except for one. Find that single one.
 * 
 * This question has a tricky solution: use ^(Exclusive Or)
 * This operator has two properties:
 * 1. a ^ a = 0 a ^ 0 = a 
 * 2. a ^ b = b ^ a
 * Therefore, if we Exclusive Or all elements, then the final result will be the distinct one element.
 * 
 *  
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int result = 0;
        for(auto i = nums.begin(); i != nums.end(); i++){
            result ^= *i;
        }
        return result;
    }
};

/**
 * A traditional Brute-Force solution is to use Map to record the count of each element. (Much slower than the tricky one but can be used in similar questions)
*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        unordered_map<int,int> cnts;
        for(auto i = nums.begin(); i != nums.end(); ++i){
            if(++cnts[*i] == 2){
                cnts.erase(*i);
            }
            
        }
        return cnts.begin()->first;
    }
};