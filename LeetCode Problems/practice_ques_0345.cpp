/* 345. REVERSE VOWELS OF A STRING

Given a string s, reverse only all the vowels in the string and return it.

The vowels are 'a', 'e', 'i', 'o', and 'u', and they can appear in both lower and upper cases, more than once.

 

Example 1:

Input: s = "hello"
Output: "holle"
Example 2:

Input: s = "leetcode"
Output: "leotcede"
 

Constraints:

1 <= s.length <= 3 * 105
s consist of printable ASCII characters.
                                                           */


class Solution {
public:
     bool isVowel(char ch){

        char ans = (ch=='a' || ch=='e' ||ch=='i' ||ch=='o' ||ch=='u' 
                   ||ch=='A' ||ch=='E' || ch=='I' ||ch=='O' ||ch=='U');
                   
        return ans;
    }
    
public:
    string reverseVowels(string s) {
        
     int start = 0;
     int end = s.size();

     while(start < end){

         if(isVowel(s[start]) && isVowel(s[end])){
             swap(s[start],s[end]);
             start++;
             end--;
         }

         else if(!isVowel(s[start]))
         start++;
         
         else
         end--;
     }
     return s;
    }
};
