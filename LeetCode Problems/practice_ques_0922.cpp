/*  922.  SORT ARRAY BY PARITY II

Given an array of integers nums, half of the integers in nums are odd, and the other half are even.

Sort the array so that whenever nums[i] is odd, i is odd, and whenever nums[i] is even, i is even.

Return any answer array that satisfies this condition.

Example 1:
Input: nums = [4,2,5,7]
Output: [4,5,2,7]
Explanation: [4,7,2,5], [2,5,4,7], [2,7,4,5] would also have been accepted.

Example 2:
Input: nums = [2,3]
Output: [2,3]
 

Constraints:
2 <= nums.length <= 2 * 104
nums.length is even.
Half of the integers in nums are even.
0 <= nums[i] <= 1000
*/


class Solution {
public:
    vector<int> sortArrayByParityII(vector<int>& nums) {
        vector<int> ans;
        vector<int> even;
        vector<int> odd;

        for(int i=0; i<nums.size(); i++) {
            if(nums[i]%2==0)
            even.push_back(nums[i]);
            else
            odd.push_back(nums[i]);
        }

        int j=0;
        int k=0;

        for(int i=0;i<nums.size();i++) {
            if(i%2==0) {
                ans.push_back(even[j]);
                j++;
            }
            else {
                ans.push_back(odd[k]);
                k++;
            }
        }
        return ans;
    }
};
