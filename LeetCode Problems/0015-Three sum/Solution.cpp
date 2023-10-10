class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
       
        vector<vector<int>> triplets;

        sort(nums.begin(), nums.end());

        for(int i=0; i<nums.size()-2; i++) {

            while((i>0 && i<nums.size()-2) && nums[i]==nums[i-1])
            i++;

            int j=i+1;
            int k=nums.size()-1;

            
            while(j<k) {

                int sum = nums[i]+nums[j]+nums[k];

                if(sum == 0) {

                    triplets.push_back({nums[i], nums[j], nums[k]});
                
                    while(j<k && nums[j]==nums[j+1])
                    j++;

                    while(j<k && nums[k]==nums[k-1])
                    k--;
   
                    j++;
                    k--;            
                }  

                else if(sum < 0)
                j++;
                
                else
                k--;
            } 
        
        }
        return triplets;
    }
};
