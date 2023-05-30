/*  917.  REVERSE ONLY LETTERS

Given a string s, reverse the string according to the following rules:

All the characters that are not English letters remain in the same position.
All the English letters (lowercase or uppercase) should be reversed.
Return s after reversing it.

Example 1:
Input: s = "ab-cd"
Output: "dc-ba"

Example 2:
Input: s = "a-bC-dEf-ghIj"
Output: "j-Ih-gfE-dCba"

Example 3:
Input: s = "Test1ng-Leet=code-Q!"
Output: "Qedo1ct-eeLg=ntse-T!"
 

Constraints:
1 <= s.length <= 100
s consists of characters with ASCII values in the range [33, 122].
s does not contain '\"' or '\\'.
                                                                      */
                                     

class Solution {
public:
    bool isLetter(char s) {

        s=(char)tolower(s);

        if(s >= 'a' and s <= 'z')
        return true;
        else
        return false;
    }

    string reverseOnlyLetters(string s) {

       int start=0;
       int end=s.size()-1;

       while(start < end) {

           if(isLetter(s[start])==true && isLetter(s[end])==true)
           swap(s[start++], s[end--]);

           else if(isLetter(s[start])==true && isLetter(s[end])==false)
           end--;

           else if(isLetter(s[start])==false && isLetter(s[end])==true)
           start++;

           else{
               start++;
               end--;
           }
       } 
       return s;
    }
};
