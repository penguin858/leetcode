#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

/*
 *
 * 904. Fruit Into Baskets
 * In a row of trees, the i-th tree produces fruit with type tree[i].
 * You start at any tree of your choice, then repeatedly perform the following steps:
 * Add one piece of fruit from this tree to your baskets.  If you cannot, stop
 * Move to the next tree to the right of the current tree.  If there is no tree to the right, stop.
 * Note that you do not have any choice after the initial choice of starting tree: you must perform step 1, then step 2, then back to step 1, then step 2, and so on until you stop.
 * You have two baskets, and each basket can carry any quantity of fruit, but you want each basket to only carry one type of fruit each.
 * What is the total amount of fruit you can collect with this procedure?
 *  
*/

/*
 * Idea: This question can be changed into 'Finding the longest substring which has two distinct characters'. The feasible solution is to use a hashmap to record current counts of the two distinct character. 
*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, start = 0, len = tree.size();
        unordered_map<int, int> fruitCnt;
        for(int i = 0 ; i < len; ++i){
            fruitCnt[tree[i]]++;
            while(fruitCnt.size() > 2){
                if(--fruitCnt[tree[start]] == 0){
                    fruitCnt.erase(tree[start]);
                }
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};

/**
 * Another possible way is to record the last position of each character rather than their counts. It will have the same performance as previous method.
*/

class Solution {
public:
    int totalFruit(vector<int>& tree) {
        int res = 0, start = 0, len = tree.size();
        unordered_map<int, int> fruitCnt;
        for(int i = 0 ; i < len; ++i){
            fruitCnt[tree[i]] = i;
            while(fruitCnt.size() > 2){
                if(fruitCnt[tree[start]] == start){
                    fruitCnt.erase(tree[start]);
                }
                start++;
            }
            res = max(res, i - start + 1);
        }
        return res;
    }
};