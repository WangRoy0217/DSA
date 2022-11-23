/*
Given two strings s and t, return true if t is an anagram of s, and false otherwise.

An Anagram is a word or phrase formed by rearranging the letters of a different word or phrase, typically using all the original letters exactly once.

Example 1:

Input: s = "anagram", t = "nagaram"
Output: true
Example 2:

Input: s = "rat", t = "car"
Output: false
 
Constraints:

1 <= s.length, t.length <= 5 * 104
s and t consist of lowercase English letters.
 
Follow up: What if the inputs contain Unicode characters? How would you adapt your solution to such a case?

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/882/
*/

class Solution {
public:
    bool isAnagram(string s, string t) {
        map <char,int> table;
        if(s.length()!=t.length())
        return false;
    for(int i=0;i<s.length();i++){
        if(table.find(s[i])==table.end())
            table[s[i]]=1;
        else
            table[s[i]]+=1;
    }
    for(int i=0;i<t.length();i++){
        if(table[t[i]]==0)
            return false;
        else{
            table[t[i]]--;
        }
    }
    return true;
        
    }
};