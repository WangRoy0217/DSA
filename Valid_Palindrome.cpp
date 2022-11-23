/*
A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, it reads the same forward and backward. Alphanumeric characters include letters and numbers.

Given a string s, return true if it is a palindrome, or false otherwise.

Example 1:

Input: s = "A man, a plan, a canal: Panama"
Output: true
Explanation: "amanaplanacanalpanama" is a palindrome.
Example 2:

Input: s = "race a car"
Output: false
Explanation: "raceacar" is not a palindrome.
Example 3:

Input: s = " "
Output: true
Explanation: s is an empty string "" after removing non-alphanumeric characters.
Since an empty string reads the same forward and backward, it is a palindrome.
 
Constraints:

1 <= s.length <= 2 * 105
s consists only of printable ASCII characters.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/883/
*/

class Solution {
public:
    int getAlphanumericCommonIndex(char c){
        int index;
        if(c >= 'a' && c <= 'z'){
            index = c - 'a';
        }
        else if(c >= 'A' && c <= 'Z'){
            index = c - 'A';
        }
        else{
            index = c - '0'+26;
        }
        
        return index;
    }
    bool isPalindrome(string s) {
        int i=0,j=s.length()-1;
    int a,b;
    while(i<j){
        while((i<j) && !(s[i] >= '0' && s[i] <= '9') && !(s[i] >= 'a' && s[i] <= 'z') && !(s[i] >= 'A' && s[i] <= 'Z'))
            i++;
        while((i<j) && !(s[j] >= '0' && s[j] <= '9') && !(s[j] >= 'a' && s[j] <= 'z') && !(s[j] >= 'A' && s[j] <= 'Z'))
            j--;
        
        a=getAlphanumericCommonIndex(s[i]);
        b=getAlphanumericCommonIndex(s[j]);
        if(a!=b)
            return false;
        i++;
        j--;

    }
    return true;
    }
};