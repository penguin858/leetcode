// class Solution(object):
//     def lengthOfLongestSubstring(self, s):
//         """
//         :type s: str
//         :rtype: int
//         """
//         a = [[0 for i in range(len(s))] for j in range(len(s))]
//         for i in range(len(s)):
//             a[i][i] = 1
//             for j in range(i + 1, len(s)):
//                 temp = a[i][i]
//                 for k in range(i, j):
//                     if s[j] in s[k : j]:
//                         temp = max(temp, a[k][j-1])
//                     else:
//                         temp = max(temp, a[k][j-1] + 1)

//         return a[len(s)-1][len(s)-1]


#include <iostream>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int ret = 0, left = 0;
        int a[256] = {0};
        for(int i = 0 ; i < s.size(); ++i){
            if(a[s[i]] == 0 || a[s[i]] < left ){
                ret = max(ret, i - left + 1);
            }
            else{
                left = a[s[i]];
            }
            a[s[i]] = i + 1;
        }
        return ret;
    }
};