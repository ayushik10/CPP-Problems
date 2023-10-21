class Solution {
public:
    int reverseNum(int n) {
      int rev = 0;

      while(n>0) {
        rev = rev*10+(n%10);
        n /= 10;
      }
      return rev;   
   }

    int countDistinctIntegers(vector<int>& nums) {
      unordered_map<int,int> mp;

      for(int i=0; i<nums.size(); i++) {
        mp[nums[i]]++;

        int rev = reverseNum(nums[i]);
        mp[rev]++;
      }
      return mp.size();
    }
};
