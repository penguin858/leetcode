#include <iostream>
using namespace std;

/*
 *
 * 115. distinct subsequences
 * Use a[i+1][j+1] to represent the number of distinct subsequences of the prefix of S which is equal to the prefix of T.
 * Initialization: a[i][0] = 1
 * 
 * DP: a[i+1][j+1] = a[i][j+1] + (S[i]==T[j] ? a[i][j] : 0)
 *  
*/

class Solution {
public:
    int numDistinct(string s, string t) {
        unsigned int a[s.length() + 1][t.length() + 1];
        memset(a, 0, (s.length() + 1) * (t.length() + 1) * sizeof(int));
        for(int i = 0 ; i <= s.length() ; ++i)
            a[i][0] = 1;

        for(int i = 0; i < s.length(); ++i){
            for(int j = 0; j < t.length(); ++j){
                a[i+1][j+1] = a[i][j+1];
                if(s[i] == t[j])
                    a[i+1][j+1] += a[i][j];
            }
        }
        return a[s.length()][t.length()];
    }
};