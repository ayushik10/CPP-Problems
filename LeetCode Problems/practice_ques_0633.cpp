/*  633. SUM OF SQUARE NUMBERS

Given a non-negative integer c, decide whether there're two integers a and b such that a2 + b2 = c.

Example 1:
Input: c = 5
Output: true
Explanation: 1 * 1 + 2 * 2 = 5

Example 2:
Input: c = 3
Output: false
 

Constraints:
0 <= c <= 231 - 1                */

class Solution {
public:
    bool judgeSquareSum(int c) {
       /* for(long long int i=1; i<c-1; i++) { 
            for(long long int j=i+1; j<c; j++){
                if((i*i)+ (j*j) == c)
                return true;
            }
        }
        return false;*/

        long long int s=0;
        long long int e=(long long int)sqrt(c);
       
        while(s<=e){
            if((s*s)+(e*e) == c)
            return true;

            else if((s*s)+(e*e) < c)
            s++;

            else
            e--;
        }
        return false;
    }
};
