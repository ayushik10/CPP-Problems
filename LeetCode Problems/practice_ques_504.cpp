/*  504.  BASE 7

Given an integer num, return a string of its base 7 representation. 

Example 1:
Input: num = 100
Output: "202"

Example 2:
Input: num = -7
Output: "-10"
 
Constraints:
-107 <= num <= 107   */

class Solution {
public:
    string convertToBase7(int num) {
        
        string ans = "";
        int n= abs(num);
        
        if(n== 0)
        return "0";

        while(n != 0) {
            int rem = n%7;
            ans+=('0'+rem);
            n = n/7;
        }
        
        if(num<0)
        ans+=('-');

        reverse(ans.begin(), ans.end());

        return ans;
    }
};
