/*
Given a string s, find the first non-repeating character in it and return its index. If it does not exist, return -1.

Example 1:

Input: s = "leetcode"
Output: 0
Example 2:

Input: s = "loveleetcode"
Output: 2
Example 3:

Input: s = "aabb"
Output: -1

Constraints:

1 <= s.length <= 105
s consists of only lowercase English letters.

https://leetcode.com/explore/interview/card/top-interview-questions-easy/127/strings/881/
*/

class Solution {
public:
    int firstUniqChar(string s) {
        
        map <char,int> table;
    for(int i=0;i<s.length();i++){
        if(table.find(s[i])==table.end())
            table[s[i]]=1;
        else
            table[s[i]]+=1;
    }
    for(int i=0;i<s.length();i++){
        if(table[s[i]]==1)
            return i;
    }
    return -1;
        
    }
};