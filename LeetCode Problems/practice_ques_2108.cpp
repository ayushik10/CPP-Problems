/*  2108. FIND FIRST PALINDROMIC STRING IN THE ARRAY

Given an array of strings words, return the first palindromic string in the array. If there is no such string, return an empty string "".

A string is palindromic if it reads the same forward and backward.

Example 1:
Input: words = ["abc","car","ada","racecar","cool"]
Output: "ada"
Explanation: The first string that is palindromic is "ada".
Note that "racecar" is also palindromic, but it is not the first.

Example 2:
Input: words = ["notapalindrome","racecar"]
Output: "racecar"
Explanation: The first and only string that is palindromic is "racecar".

Example 3:
Input: words = ["def","ghi"]
Output: ""
Explanation: There are no palindromic strings, so the empty string is returned.
 

Constraints:
1 <= words.length <= 100
1 <= words[i].length <= 100
words[i] consists only of lowercase English letters.            */



class Solution {
private:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.size()-1;

        while(start <= end) {
            
            if(s[start] != s[end])
            return false;

            else {
                start++;
                end--;
            } 
        }
        return true;
    }

public:
    string firstPalindrome(vector<string>& words) {
        string ans = "";

        for(int i=0; i<words.size(); i++) {
            if(isPalindrome(words[i])) {
                ans = words[i];
                return ans;
            }
        }
        return ans;
    }
};
