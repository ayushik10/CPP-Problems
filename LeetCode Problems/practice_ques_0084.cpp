/*  84. LARGEST RECTANGLE IN HISTOGRAM.

Given an array of integers heights representing the histogram's bar height where the width of each bar is 1, return the area of the largest rectangle in the histo

Example 1:
Input: heights = [2,1,5,6,2,3]
Output: 10
Explanation: The above is a histogram where width of each bar is 1.
The largest rectangle is shown in the red area, which has an area = 10 units.

Example 2:
Input: heights = [2,4]
Output: 4
 

Constraints:
1 <= heights.length <= 105
0 <= heights[i] <= 104               */


class Solution {
private:
    vector<int> nextSmallerElement(vector<int> arr, int n){
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i=n-1; i>=0; i--){
            
            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }    
    vector<int> prevSmallerElement(vector<int> arr, int n){
        stack<int> st;
        st.push(-1);

        vector<int> ans(n);

        for(int i=0; i<n; i++){

            while(st.top() != -1 && arr[st.top()] >= arr[i]){
                st.pop();
            }
            ans[i] = st.top();
            st.push(i);
        }
        return ans;
    }    
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();

        vector<int> next(n);
        next = nextSmallerElement(heights, n);

        vector<int> prev(n);
        prev = prevSmallerElement(heights, n);

        int area = 0;
        for(int i=0; i<n; i++){
            int length = heights[i];

            if(next[i] == -1){
               next[i] = n;
            }
            int breadth = next[i] - prev[i] - 1;

            int newArea = length*breadth;
            area = max(newArea, area);
        }
        return area;
    }
};
