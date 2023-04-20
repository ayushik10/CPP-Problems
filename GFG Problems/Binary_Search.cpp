// User function template for C++

class Solution {
  public:
    int binarysearch(int arr[], int n, int k) {
        int s = 0;
        int e = n-1;
        
        while (s <= e){
            
            int mid = (s+e)/2;
            
            if (arr[mid] == k){
            return mid;
            }
            
            else if (arr[mid] < k){
            s = mid +1;
            }
            
            else{
            e = mid-1;
            }
            mid = (s+e)/2;
        }
        return -1;
    }
};
