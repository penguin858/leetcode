#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/**
 * 
 * 575. Distribute Candies
 * Given an integer array with even length, where different numbers in this array represent different kinds of candies. 
 * Each number means one candy of the corresponding kind. 
 * You need to distribute these candies equally in number to brother and sister. 
 * Return the maximum number of kinds of candies the sister could gain.
 * 
 * This question is very simple. Just find the smaller number between half of candies and total kinds of candies.
 * 
*/

class Solution {
public:
    /*
     * Use to calculate the total kinds of candies.
     */
    int kinds(vector<int> &candies){
        unordered_map<int,int> cnts;
        int kind = 0;
        for(auto it = candies.begin(); it != candies.end(); ++it){
            if(++cnts[*it] == 1)
                kind++;
        }
        return kind;
    }
    int distributeCandies(vector<int>& candies) {
        return min(kinds(candies), (int)((candies.size())/2));
    }
};