/*  704. BINARY SEARCH - recursive approach

Given an array of integers nums which is sorted in ascending order, and an integer target, write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

You must write an algorithm with O(log n) runtime complexity.

Example 1:

Input: nums = [-1,0,3,5,9,12], target = 9
Output: 4
Explanation: 9 exists in nums and its index is 4
Example 2:

Input: nums = [-1,0,3,5,9,12], target = 2
Output: -1
Explanation: 2 does not exist in nums so return -1


Constraints:

1 <= nums.length <= 104
-104 < nums[i], target < 104
All the integers in nums are unique.
nums is sorted in ascending order.             */

// RECURSIVE APPROACH

class Solution {
public:
    int binarySearch(vector<int>& nums, int s, int e, int target) {
        
        int mid = (s+e)/2;

        if(s>e)
        return -1;

        if(nums[mid] == target)
        return mid;
        
        if(nums[mid]<target)
        return binarySearch(nums, mid+1, e, target);

        else
        return binarySearch(nums, s, mid-1, target);
    }
    
    int search(vector<int>& nums, int target) {
       return binarySearch(nums, 0, nums.size()-1, target);
    }
};


// ITERATIVE APPROACH

class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        int s = 0;
        int e = nums.size()-1;
        
        while(s<=e){
            int mid = (s+e)/2;

            if(target == nums[mid])
                return mid;

            else if(target < nums[mid])
                e = mid-1;

            else
            s = mid+1;
        }
        return -1;
    }
};
