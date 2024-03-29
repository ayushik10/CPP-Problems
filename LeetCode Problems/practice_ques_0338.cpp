/*  338. COUNTING BITS

Given an integer n, return an array ans of length n + 1 such that for each i (0 <= i <= n), ans[i] is the number of 1's in the binary representation of i.

Example 1:
Input: n = 2
Output: [0,1,1]
Explanation:
0 --> 0
1 --> 1
2 --> 10
  
Example 2:
Input: n = 5
Output: [0,1,1,2,1,2]
Explanation:
0 --> 0
1 --> 1
2 --> 10
3 --> 11
4 --> 100
5 --> 101
 

Constraints:
0 <= n <= 105
*/


class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> ans;

        for(int i=0; i<=n; i++) {
            int sum=0;
            int temp=i;

            while(temp!=0) {
                sum += temp%2;
                temp = temp/2;
            }
            ans.push_back(sum);
        }
        return ans;
    }
};
