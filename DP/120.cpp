#include <iostream>

using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int row = triangle.size();
        int a[row][row];
        for(int i = 0 ; i < row ; ++i)
            a[row-1][i] = triangle[row-1][i];
        for(int i = row - 2; i >=0 ; --i){
            a[i][row-1] = a[i+1][row-1] + triangle[i][row-1];
            for(int j = row - 2; j >= 0; --j){
                a[i][j] = min(a[i+1][j], a[i+1][j+1]) + triangle[i][j];
            }
        }
        return a[0][0];
    }
};