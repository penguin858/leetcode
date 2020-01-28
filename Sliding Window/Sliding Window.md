# Sliding Window Question 

When using Brute Force Approach, we need to use 2 loops to solve this kind of problems. The Sliding Window Technique can reduce it to a single loop:

1. We compute the sum of first k elements out of n terms using a linear loop and store the sum in variable window_sum.
2. Then we will graze linearly over the array till it reaches the end and simultaneously keep track of maximum sum.
3. To get the current sum of block of k elements just subtract the first element from the previous block and add the last element of the current block .

Then the computational complexity will decrease from O(kn) to O(n).