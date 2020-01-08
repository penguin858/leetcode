#include <iostream>

using namespace std;

/*
 * It is a basic dp question.
 * Use a[i][j] to represent whether the i letter prefix of s can be matched by j letter prefix of p
 * a[i][j] =    false if s[i] != p[j]
 *              a[i-1][j-1] if s[i] == p[j]
 *              a[i-1][j-1] if p[j] == '.'
 *              {Any a[k][j-1], k <= i} if p[j] == '*'
*/

class Solution {
public:
    bool isMatch(string s, string p) {
        bool a[s.length()+1][p.length()+1];
        memset(a, 0, (s.length()+1) * (p.length()+1) * sizeof(bool));
        a[0][0] = true;
        for(int i = 0 ; i <= s.size(); i++){
            for(int j = 1 ; j <= p.size() ; j++){
                if(i > 0 && p[j-1] == '.')
                    a[i][j] = a[i-1][j-1];
                else if(p[j-1] == '*'){
                    a[i][j] = a[i][j-2] || ( (i > 0 && (s[i-1] == p[j-2] || p[j-2] == '.') ) && a[i-1][j]);
                }
                else{
                    if(i > 0 && s[i-1] == p[j-1])
                        a[i][j] = a[i-1][j-1];
                    else
                        a[i][j] = false;
                }
            }
        }
        return a[s.length()][p.length()];
    }
};