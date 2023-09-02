/*  16. 3SUM CLOSEST

Given an integer array nums of length n and an integer target, find three integers in nums such that the sum is closest to target.

Return the sum of the three integers.

You may assume that each input would have exactly one solution.

Example 1:
Input: nums = [-1,2,1,-4], target = 1
Output: 2
Explanation: The sum that is closest to the target is 2. (-1 + 2 + 1 = 2).

Example 2:
Input: nums = [0,0,0], target = 1
Output: 0
Explanation: The sum that is closest to the target is 0. (0 + 0 + 0 = 0).
 

Constraints:
3 <= nums.length <= 500
-1000 <= nums[i] <= 1000
-104 <= target <= 104   */

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int sum=0;
        int ans=0;
        int dif = INT_MAX;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++) {

            //while((i>0 && i<nums.size()-2) && nums[i]==nums[i-1])
           // i++;

            int j=i+1;
            int k=nums.size()-1;
            
            while(j<k) {

                sum = nums[i]+nums[j]+nums[k];

                if(sum == target) 
                return target; 

                else if(sum < target)
                j++;
                
                else
                k--;
            
                if(abs(target-sum) < dif) {

                    dif= abs(target-sum);
                    ans = sum;
                }
            }
        }
        return ans;
    }
};
