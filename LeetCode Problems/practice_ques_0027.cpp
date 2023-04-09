class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        
        int s = 0;
        int e = nums.size()-1;

        for(int i=0; i<=e; i++){
            if(nums[i] != val)
            nums[s++] = nums[i];
        }
        return s;
    }
};
