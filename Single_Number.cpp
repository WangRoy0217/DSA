
/*
https://leetcode.com/explore/interview/card/top-interview-questions-easy/92/array/549/
*/
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        ios_base::sync_with_stdio(0);
        cin.tie(0);
        cout.tie(0);
        int tmp = 0;
        for(auto i : nums){
            tmp^=i;
        }
        return tmp;
        
        
    }
};