//Final Prices With a Special Discount in a Shop

/*
You are given an integer array prices where prices[i] is the price of the ith item in a shop.

There is a special discount for items in the shop. If you buy the ith item, then you will receive a discount equivalent to prices[j] where j is the minimum index such that j > i and prices[j] <= prices[i]. Otherwise, you will not receive any discount at all.

Return an integer array answer where answer[i] is the final price you will pay for the ith item of the shop, considering the special discount.

Example:

Input: prices = [10,1,1,6]
Output: [9,0,1,6]

*/

class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        stack<int*> s;
        for(int& i : prices)
        {
            while(!s.empty() &&  i <= *(s.top()) )
            {
                *(s.top()) -= i;
                s.pop();
            }
            s.push(&i);
        }
        return prices;
        
    }
};