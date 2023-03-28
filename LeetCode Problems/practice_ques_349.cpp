class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        vector<int> ans;

        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums1[i] == nums2[j]){
                  ans.push_back(nums1[i]);
                }
            }
        }
      int size = ans.size()-1;
      for(int i=0; i<size; i++){
          if(ans[i] == ans[i+1]){
              ans.erase(ans.begin()+i);
              i--;
          }
          size = ans.size()-1;
      }
      return ans;
    }
};