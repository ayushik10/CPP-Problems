class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

      int size = nums.size()-1;

      for(int i=0; i<size; i++){
          
          if(nums[i] == nums[i+1]){
              nums.erase(nums.begin()+i);
              i--;
          }
          size = nums.size()-1;
      }
    
      return nums.size();
    }
    
};
