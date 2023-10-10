lass Solution {
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
